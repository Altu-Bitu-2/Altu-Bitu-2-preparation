#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 20;

vector<int> arr(SIZE);

//a ~ b를 역순으로 배치하는 함수
void reverseAtoB(int a, int b) {
    //더하고 빼는 변화값을 증가변수로 줘서 사용, 절반까지만
    for (int i = 0; i <= (b - a) / 2; i++) {
        swap(arr[a + i], arr[b - i]);
    }
}

/**
 * 단순 구현 문제.
 * 카드를 역순으로 두기 = 수열을 반으로 접었다 생각할 때, 마주보는 원소끼리 swap!
 */

int main() {
    int a, b;

    //카드 초기화
    for (int i = 0; i < SIZE; i++) {
        arr[i] = i + 1;
    }
    //입력 & 연산
    for (int i = 0; i < 10; i++) {
        cin >> a >> b;
        reverseAtoB(a - 1, b - 1);
    }
    //출력
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << ' ';
    }
    return 0;
}