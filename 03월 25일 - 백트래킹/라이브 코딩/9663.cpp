#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 15;

int n, ans;
vector<bool> check_col(SIZE); //열 체크
vector<bool> check_left(SIZE * 2); //좌하향 대각선 체크
vector<bool> check_right(SIZE * 2); //우하향 대각선 체크

void backtracking(int row) { //row: 행
    if (row == n) { //기저조건, n개의 퀸이 모두 놓임
        ans++; //정답 증가
        return;
    }
    for (int i = 0; i < n; i++) { //i: 열
        if (!check_col[i] && !check_left[row + i] && !check_right[row - i + n]) { //모두 false여야 배치 가능
            //(row, i)에 퀸 배치 -> 그에 따른 열, 좌하향 대각선, 우하향 대각선 체크해줌
            check_col[i] = true;
            check_left[row + i] = true;
            check_right[row - i + n] = true;
            backtracking(row + 1); //다음 행 호출
            //재탐색이 가능하도록 원래상태로 돌려놓음
            check_col[i] = false;
            check_left[row + i] = false;
            check_right[row - i + n] = false;
        }
    }

}

/**
 * [백트래킹 풀이]
 *
 * 가지치기 시 유망성 검사하는 부분의 시간복잡도 O(1)
 *
 * 시간 약 1680ms
 *
 * !주의! 파이썬 사용 시 python3 말고 pypy3로 제출해야 시간초과 안남
 */

int main() {
    //입력
    cin >> n;

    //연산
    backtracking(0);

    //출력
    cout << ans << '\n';
    return 0;
}