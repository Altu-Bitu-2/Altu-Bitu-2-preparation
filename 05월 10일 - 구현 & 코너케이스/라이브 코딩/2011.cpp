#include <iostream>
#include <vector>

using namespace std;
const int MOD = 1e6; //모듈러 연산 상수

int cntPassword(int n, string s) {
    vector<int> dp(n + 1, 0);
    if (s[0] == '0') { //첫 시작이 '0'인 경우
        return 0;
    }

    dp[0] = dp[1] = 1; //s[0]의 암호 해석 경우의 수 1로 초기화, dp[0]은 더미 인덱스
    for (int i = 2; i <= n; i++) {
        int cur = i - 1; //s는 0부터 시작하고 dp는 1부터 시작하도록 설정했기 때문에 현재 s 인덱스에 접근하기 위해 i - 1
        if (s[cur] == '0' && (s[cur - 1] < '1' || s[cur - 1] > '2')) { //30, 40 이런 경우가 있을 시 암호 해독 불가
            return 0;
        }

        if (s[cur] != '0') { //한 글자 암호 해석 가능
            dp[i] += dp[i - 1]; //dp[i - 1]에서 이어서 해석
        }
        if (s[cur - 1] == '1' || (s[cur] <= '6' && s[cur - 1] == '2')) { //두 글자 암호 해석 가능
            dp[i] += dp[i - 2]; //dp[i - 2]에서 이어서 해석
        }
        dp[i] %= MOD;
    }
    return dp[n];
}

int main() {
    string s;

    //입력
    cin >> s;

    //연산 & 출력
    cout << cntPassword(s.length(), s);
    return 0;
}