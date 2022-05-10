#include <iostream>
#include <vector>

using namespace std;
const int MOD = 1e6; //모듈러 연산 상수

int cntPassword(int n, string s) {
    vector<int> dp(n + 1, 0);
    if (s[0] == '0') { //첫 시작이 '0'인 경우
        return 0;
    }

    //입력 문자열 dp배열과 인덱스 맞추기 위해 앞에 더미문자 더하기
    s = ' ' + s;
    //s[1]의 암호 해석 경우의 수 1로 초기화, dp[0]은 더미 인덱스
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (s[i] == '0' && (s[i - 1] < '1' || s[i - 1] > '2')) { //30, 40 이런 경우가 있을 시 암호 해독 불가
            return 0;
        }

        if (s[i] != '0') { //한 글자 암호 해석 가능
            dp[i] += dp[i - 1]; //dp[i - 1]에서 이어서 해석
        }
        if (s[i - 1] == '1' || (s[i] <= '6' && s[i - 1] == '2')) { //두 글자 암호 해석 가능
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