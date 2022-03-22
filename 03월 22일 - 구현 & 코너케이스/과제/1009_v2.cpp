#include <iostream>

using namespace std;

/**
 * [분산처리]
 *
 * a^b의 일의 자리를 구하는 문제 -> 따라서 수를 모두 곱해서 저장할 필요 없음
 *
 * 일의 자리만 계속 곱하고 취하자!
 * 마지막 남은 일의 자리 출력
 * 0이 나올 경우, 10번 컴퓨터가 처리하므로 0이 출력되지 않도록 예외처리
 */

int main() {
    int t, a, b;

    //입력
    cin >> t;
    while (t--) {
        cin >> a >> b;

        int one_digit = 1;
        while (b--) {
            one_digit *= a;
            one_digit %= 10;
        }
        if (one_digit == 0) {
            cout << "10\n";
            continue;
        }
        cout << one_digit << '\n';
    }
    return 0;
}