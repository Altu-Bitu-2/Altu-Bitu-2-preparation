#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int tieNumber(int n, int cnt1, vector<int> &num) {
    int ans = cnt1;
    for (int i = n - 1; i >= 0; i -= 2) {
        if (num[i] <= 1) {
            break;
        }
        if (i == 0 || num[i - 1] <= 1) {
            ans += num[i];
            break;
        }
        ans += num[i] * num[i - 1];
    }
    for (int i = 0; i < n; i += 2) {
        if (num[i] > 0) {
            break;
        }
        if (i == n - 1 || num[i + 1] > 0) {
            ans += num[i];
            break;
        }
        ans += num[i] * num[i + 1];
    }
    return ans;
}

/**
 * [수 묶기]
 *
 * 1. 제일 큰 양수부터 1보다 클 때까지 수를 묶음
 * 2. 1은 묶지 않아야 더했을 때 더 큰 수가 됨 -> 입력 받을 때, 1의 개수 카운트해서 따로 더해줌
 * 3. 제일 작은 음수부터 0까지 수를 묶음 (음수가 하나 남으면 0과 묶임)
 */

int main() {
    int n, cnt1 = 0;

    //입력
    cin >> n;
    vector<int> num(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        if (num[i] == 1) {
            cnt1++;
        }
    }

    //연산
    sort(num.begin(), num.end());

    //연산 & 출력
    cout << tieNumber(n, cnt1, num);
    return 0;
}