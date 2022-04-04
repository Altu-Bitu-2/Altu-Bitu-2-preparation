#include <iostream>
#include <vector>

using namespace std;
const int MAX = 10;

vector<int> dp(MAX + 1);

//top-down 방식 dp 채우기
int numberOfAllCases(int a) {
    if (a < 0) {
        return 0;
    }
    if (a == 0) {
        return 1;
    }
    if (dp[a]) {
        return dp[a];
    }
    for (int i = 1; i <= 3; i++) {
        dp[a] += numberOfAllCases(a - i);
    }
    return dp[a];
}

/**
 * [top-down 접근]
 * n부터 시작해서 -1, -2, -3한 수의 경우의 수 먼저 구함
 * 0미만일 경우 합으로 나타낼 수 없는 경우이므로 0 리턴
 * 이미 dp[n] 값이 있을 경우, 바로 리턴
 *
 * 테스트케이스로 입력이 들어오고, 입력 범위가 11로 작기 때문에 미리 dp 배열 채우고 시작하는 것이 더 효율적
 */

int main() {
    int t, n;

    //미리 dp 채우기
    numberOfAllCases(MAX);

    //입력
    cin >> t;
    while (t--) {
        cin >> n;

        //출력
        cout << dp[n] << '\n';
    }
    return 0;
}