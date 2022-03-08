//
// Created by JIYOUNG.P on 2022-03-02.
//

#include <iostream>
#include <vector>

using namespace std;

// 에라토스테네스의 체를 활용해 소수를 찾는 함수
int findPrime(int n, int k) {
    vector<bool> is_prime(n + 1, true);
    // 0과 1은 소수가 아니므로 미리 표기
    is_prime[0] = is_prime[1] = false;

    // 현재까지 지워진 수를 기록
    int cnt = 0;

    for (int i = 2; i <= n; i++) {
        // i가 소수라면 == i가 아직 지워지지 않았다면
        if (is_prime[i]) {
            // 이 문제에서는 i도 지워야 함 => 초기조건 j = i
            // 이 문제에서는 n까지 모든 수를 다 살펴보며 지워야 하기 때문에, j <= n 으로 설정합니다.
            for (int j = i; j <= n; j += i) {
                // cout << cnt+1 << "번째 지워지는 수 " << j << '\n'; // 디버깅용
                if (is_prime[j]) {
                    is_prime[j] = false;
                    // cnt를 +1한 후, k와 같은지 비교하고, 같다면 j를 리턴한다.
                    if (++cnt == k) {
                        return j;
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    int n, k;
    // 입력
    cin >> n >> k;

    // 연산 + 출력
    cout << findPrime(n, k);
    return 0;
}