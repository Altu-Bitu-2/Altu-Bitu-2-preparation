#include <iostream>

using namespace std;

int func(int n, int sum) {
    int ans = 0;

    if (sum > n) {
        return 0;
    }
    if (n == sum) {
        return 1;
    }
    for (int i = 1; i <= 3; i++) {
        ans += func(n, sum + i);
    }
    return ans;
}

/**
 * 재귀함수 풀이
 */

int main() {
    int t, n;

    //입력
    cin >> t;
    while (t--) {
        cin >> n;

        //연산 & 출력
        cout << func(n, 0) << '\n';
    }
    return 0;
}