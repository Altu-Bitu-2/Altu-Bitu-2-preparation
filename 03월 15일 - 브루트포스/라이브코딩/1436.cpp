#include <iostream>

using namespace std;

int getEndNumber(int n){
    int num = 665;      // 666부터 탐색 시작

    while (n) { // n이 0이 될때까지 -> 숫자를 n개 찾을 때까지
        string s = to_string(++num);
        if (s.find("666") != s.npos) {
            n--;
        }
    }
    return num;
}

int main(){
    int n;

    // 입력
    cin >> n;
    // 연산 + 출력
    cout << getEndNumber(n);
    return 0;
}