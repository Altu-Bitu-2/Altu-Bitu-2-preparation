#include <iostream>
#include <cmath>

using namespace std;

string solution(int x, int n) {
    if (n > 1 && n % 2 == 1) {
        return "ERROR";
    }
    if (n == 1 && x < 0) {
        return "INFINITE";
    }
    if (n == 1 || x <= 0) {
        return "0";
    }
    if (n == 0) {
        return "INFINITE";
    }
    int minus = n / 2;
    int cnt = ceil((double) (x - minus) / minus);
    return to_string(cnt);
}

/**
 * [화살표 연산자]
 *
 * 1. n이 1보다 큰 홀수인 경우 -> ERROR
 * 2. n이 1인데 x가 음수인 경우 -> while문 조건 항상 참 -> INFINITE
 * 3. n이 1인데 x가 양수인 경우 or x가 0보다 작거나 같은 경우 -> while문에 진입 못함 -> 0
 * 4. n이 0인데 x가 양수인 경우 -> while문 조건 항상 참 -> INFINITE
 * 5. 나머지 경우엔 x - (n/2) 한 수를 (n/2)로 나눈 몫을 올림해서 출력 (n/2: 감소 연산자에 의해 빼는 값)
 */

int main() {
    int x, n;

    //입력
    cin >> x >> n;

    //연산 & 출력
    cout << solution(x, n);
    return 0;
}