//
// Created by JIYOUNG.P on 2022-03-08.
//

#include <iostream>
#include <vector>

using namespace std;

// gcd 자체는 최대 1,000,000이므로 int 범위 안에 들어옴
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// 입력값이 최대 1,000,000, n이 최대 100이므로
// C(100, 2) = 4950, 4950 * 1,000,000 = 4,950,000,000
// INT 범위를 벗어남 -> long long
long long gcdSum(int n, vector<int> &v) {
    long long sum = 0;

    // 가능한 모든 쌍의 최대공약수를 구해서, sum에 더하기
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            sum += gcd(max(v[i], v[j]), min(v[i], v[j]));
        }
    }
    return sum;
}

int main() {
    // 입력
    int t;
    cin >> t;

    // 입력 + 연산
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        // 출력
        cout << gcdSum(n, arr) << '\n';
    }
}