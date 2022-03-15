//
// Created by JIYOUNG.P on 2022-03-01.
//

#include <iostream>

using namespace std;

// O(n)으로 연산
int gcdBad(int a, int b) {
    // 두 수 중 작은 것을 기준으로 공통 약수가 나오는 순간 리턴한다.
    for (int i = min(a, b); i > 0; i--) {
        if (a % i == 0 && b % i == 0) {
            return i;
        }
    }
}

// 유클리드 호제법으로 연산.
int gcdRecursion(int a, int b) {
    // a가 b보다 크다고 가정하고, 유클리드 연산법 사용.
    if (b == 0) {
        return a;
    }
    return gcdRecursion(b, a % b);
}

int main() {
    // 입력
    int a, b;
    cin >> a >> b;

    // 최대공약수 & 최소공배수 구하기
    int g = gcdRecursion(a, b);
    int l = (a * b) / g;

    // 출력
    cout << g << '\n' << l;
    return 0;
}