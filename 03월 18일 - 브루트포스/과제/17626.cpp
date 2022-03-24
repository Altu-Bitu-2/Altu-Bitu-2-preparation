#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int findMinNumber(int n, int num_size, vector<int> &square_num) {
    int ans = 4;
    for (int i = num_size - 1; i >= 0; i--) {
        int sum1 = square_num[i];
        if (sum1 == n) {
            ans = min(ans, 1);
        }
        for (int j = num_size - 1; j >= 0; j--) {
            int sum2 = sum1 + square_num[j];
            if (sum2 == n) {
                ans = min(ans, 2);
            }
            for (int k = num_size - 1; k >= 0; k--) {
                int sum3 = sum2 + square_num[k];
                if (sum3 == n) {
                    ans = min(ans, 3);
                }
            }
        }
    }
    return ans;
}

/**
 * [Four Squares]
 * 자연수 n에 대해 최소 몇개의 제곱수의 합으로 표현할 수 있는지 찾는 문제
 * 미리 최댓값까지의 제곱수를 구해놓고, 완전탐색
 *
 * 1 ~ 3개 조합으로 불가능한 경우, 답은 무조건 4가 된다 -> 4개의 합은 시도해보지 않아도 된다.
 *
 * sqrt(50000) = 약 223
 * 전체 연산 수  < 223^2 + 223^3 = 11139296 <1억 -> 브루트포스 가능
 */

int main() {
    int n, num_size;
    vector<int> square_num;

    //입력
    cin >> n;

    //연산
    for (int i = 1; i <= sqrt(n); i++) { //미리 루트 n 까지의 제곱수 저장
        square_num.push_back(i * i);
    }
    num_size = square_num.size(); //제곱수 개수

    //출력
    cout << findMinNumber(n, num_size, square_num);
    return 0;
}