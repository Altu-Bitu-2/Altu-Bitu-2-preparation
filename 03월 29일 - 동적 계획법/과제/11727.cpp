#include <iostream>
#include <vector>

using namespace std;

int fillTile(int n) {
    vector<int> dp(n + 1, 0);

    //너비 1, 2인 타일 채우는 경우의 수 미리 초기화
    dp[1] = 1;
    dp[2] = 3;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + 2 * dp[i - 2];
        dp[i] %= 10007;
    }
    return dp[n];
}

/**
 * 너비를 인덱스로 써서 n까지의 너비를 채우는 방법의 수를 저장하자!
 *
 * 우선, 너비 1은 2(높이)x1(너비) 타일로 채우는 경우밖에 없음
 * 너비 2는 1x2 2개와 2x2 1개 총 2 경우 + 너비 1에 2x1 타일을 더한 1 경우 -> 3 경우
 *
 * 그 후, 너비 3부터는 각각 너비 1, 2만큼을 뺀 타일에서 1, 2 너비 타일을 각각 더하는 경우를 생각해주자
 * 이때, 중복 경우의 수가 생기지 않도록 너비 2의 경우에서 1에서 더한 경우는 빼줌
 * -> dp[n] = (너비 1인 타일 채우는 경우의 수 = 1) * dp[n - 1]
 *          + (너비 2인 타일 채우는 경우의 수 = 2) * dp[n - 2]
 *
 * -> dp[n] = 1 * dp[n - 1] + 2 * dp[n - 2] (n >= 3)
 *
 * !주의! 모듈러 연산 해야함
 */

int main() {
    int n;

    //입력
    cin >> n;

    //연산 & 출력
    cout << fillTile(n);
    return 0;
}