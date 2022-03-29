#include <iostream>
#include <vector>

using namespace std;

//top-down 방식 dp
vector<int> dp_top;
int numberOfCasesTop(int n) {
    if (n < 0) {
        return 0;
    }
    if (n == 0) {
        return dp_top[0] = 1;
    }
    if (dp_top[n]) {
        return dp_top[n];
    }
    for (int i = 1; i <= 3; i++) {
        dp_top[n] += numberOfCasesTop(n - i);
    }
    return dp_top[n];
}

//bottom-up 방식 dp
int numberOfCases(int n) {
    vector<int> dp(n + 1, 0);

    dp[0] = dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    return dp[n];
}

/**
 * [top-down 접근]
 * n부터 시작해서 -1, -2, -3한 수의 경우의 수 먼저 구함
 * 0미만일 경우 합으로 나타낼 수 없는 경우이므로 0 리턴
 * 이미 dp[n] 값이 있을 경우, 바로 리턴
 *
 * [bottom-up 접근]
 * 각 수를 인덱스로 써서 정수 n까지 1, 2, 3의 합으로 나타내는 방법의 수를 저장하자!
 *
 * 우선 3까지 1, 2, 3의 합으로 나타내는 방법의 수 초기화 함
 * 해당 인덱스에서 -1, -2, -3 한 인덱스에 +1, +2, +3을 해줬다고 생각하면 됨
 *
 * -> dp[n] = dp[n - 1] + dp[n - 2] + dp[n - 3] (n >= 3)
 *
 * 해당 풀이는 인덱스 관리를 편하게 하기 위해 0을 더미 인덱스로 줘서 인덱스 3부터 연산
 */

int main() {
    int t, n;

    //입력
    cin >> t;
    while (t--) {
        cin >> n;

        //연산 & 출력
        //bottom-up 방식
        //cout << numberOfCases(n) << '\n';
        //top-down 방식
        dp_top.assign(n + 1, 0);
        cout << numberOfCasesTop(n) << '\n';
    }
    return 0;
}