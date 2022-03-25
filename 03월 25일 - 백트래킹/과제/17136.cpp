#include <iostream>

using namespace std;
const int SIZE = 10;
const int INF = 26;

int paper[SIZE][SIZE];
int paper_cnt[5] = {5, 5, 5, 5, 5};
int ans = INF;

bool promising(int row, int col, int paper_size) {
    bool check = true;
    for (int i = row; i < row + paper_size; i++) { //색종이 크기 만큼 돌면서 모두 1인지 확인
        for (int j = col; j < col + paper_size; j++) {
            if (paper[i][j] == 0) {
                check = false;
                break;
            }
        }
    }
    return check;
}

void attach_detach(int row, int col, int paper_size, bool is_attach) {
    for (int i = row; i < row + paper_size; i++) {
        for (int j = col; j < col + paper_size; j++) {
            paper[i][j] = !is_attach;
        }
    }
}

void backtracking(int row, int col, int count) { //row: 행, col: 열, count: 색종이 개수
    while (paper[row][col] != 1) { //1인 곳 찾을 때까지
        if (col < 10) {
            col++;
        } else if (col == 10) {
            row++;
            if (row == 10) {
                ans = min(ans, count);
                return;
            }
            col = 0;
        }
    }
    if (ans <= count) {
        return;
    }
    for (int i = 5; i >= 1; i--) { //5 ~ 1까지 색종이 다 붙여보기
        if (row + i > 10 || col + i > 10 || !paper_cnt[i]) {
            continue;
        }
        if (promising(row, col, i)) {
            paper_cnt[i - 1]--;
            attach_detach(row, col, i, true);
            backtracking(row, col, count + 1);
            paper_cnt[i - 1]++;
            attach_detach(row, col, i, false);
        }
    }
}

int main() {
    //입력
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> paper[i][j];
        }
    }

    //연산
    backtracking(0, 0, 0);
    if (ans == INF) {
        ans = -1;
    }

    //출력
    cout << ans;
    return 0;
}
