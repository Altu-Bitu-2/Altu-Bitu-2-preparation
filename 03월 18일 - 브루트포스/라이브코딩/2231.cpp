#include <iostream>

using namespace std;

// 가장 작은 생성자 리턴
int findConstructor(int n) {
    // n까지 분해합을 구해보며 분해합이 n인 경우를 찾는다
    int sum, temp;

    for (int i = 1; i < n; i++) {
        // 반복문 내에서 i를 변경하면 안되므로, 값 복사
        temp = i;
        sum = temp;     // 해당 수를 더하고

        // 각 자리 수 더하기
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }

        // 생성자가 맞으면 바로 리턴
        if (sum == n) {
            return i;
        }
    }

    // 생성자가 없는 경우
    return 0;
}

int main() {
    int n;

    // 입력
    cin >> n;
    // 연산 + 출력
    cout << findConstructor(n);
}