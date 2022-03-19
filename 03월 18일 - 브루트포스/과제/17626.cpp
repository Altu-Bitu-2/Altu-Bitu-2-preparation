#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, num_size;
int ans = 4; //우선 4로 초기화
vector<int> square_num;

void findMinNumber(int cnt, int sum, int m) { //cnt: 고른 개수, sum: 지금까지 합, m: 골라야 하는 개수
    if (cnt == m) { //다 골랐다면
        if (sum == n) { //제곱수 합이 n과 같다면
            ans = m;
        }
        return;
    }
    for (int i = num_size; i >= 0; i--) {
        if (sum <= n) {
            findMinNumber(cnt + 1, sum + square_num[i], m);
            if (ans != 4) { //새로운 정답
                return;
            }
        }
    }
}

/**
 * [Four Squares]
 * 자연수 n에 대해 최소 몇개의 제곱수의 합으로 표현할 수 있는지 찾는 문제
 * 미리 최댓값까지의 제곱수를 구해놓고, 완전탐색
 *
 * 1. 1 ~ 3개의 조합으로 불가능한 경우, 답은 무조건 4가 된다 -> 4개의 합은 시도해보지 않아도 된다.
 *
 * sqrt(50000) = 약 223
 * 전체 연산 수  < 223^2 + 223^3 = 11139296 <1억 -> 브루트포스 가능
 */

int main() {
    //입력
    cin >> n;

    //연산
    for (int i = 1; i <= sqrt(n); i++) { //미리 루트 n 까지의 제곱수 저장
        square_num.push_back(i * i);
    }
    num_size = square_num.size(); //제곱수 개수

    //3개의 조합까지만 구함
    for (int i = 1; i <= 3; i++) {
        findMinNumber(0, 0, i);
        if (ans != 4) { //정답 생기면
            break;
        }
    }

    //출력
    cout << ans;
    return 0;
}