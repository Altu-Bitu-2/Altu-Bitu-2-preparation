#include <iostream>

using namespace std;

const int SIZE = 8;

//재귀함수 사용 시, 함수를 계속 호출할 때 매개변수도 생성되므로 전역변수로 선언하는 것이 더 효율적
int n, m;
int num[SIZE]; //수열
bool check[SIZE]; //수 사용 체크 배열

//재귀함수로 구현한 백트래킹
void backtracking(int cnt) { //cnt: 수열의 인덱스
    if (cnt == m) { //기저조건, 길이 m 수열 만든 경우
        for (int i = 0; i < cnt; i++) { //바로 출력
            cout << num[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!check[i]) { //현재 수열에 해당 수가 없어야 사용 가능
            num[cnt] = i; //수열에 값 저장
            check[i] = true; //수 사용
            backtracking(cnt + 1); //다음 수열 인덱스 호출
            check[i] = false; //원래 상태로 돌려놓음
        }

    }
}

int main() {
    //입력
    cin >> n >> m;

    //연산 + 출력
    backtracking(0);

    return 0;
}