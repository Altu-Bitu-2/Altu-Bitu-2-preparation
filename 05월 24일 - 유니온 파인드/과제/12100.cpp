#include <iostream>
#include <vector>

using namespace std;

int n, ans = 0;
vector<vector<int>> board;

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

void upMove() {
    vector<vector<int>> temp(n, vector<int>(n, 0));
    for (int j = 0; j < n; j++) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (board[i][j]) {
                temp[cnt++][j] = board[i][j];
            }
        }
    }
    board = temp;
    temp.assign(n, vector<int>(n, 0));
    for (int j = 0; j < n; j++) {
        int cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            if (board[i][j] && board[i][j] == board[i + 1][j]) {
                board[i + 1][j] = 0;
                temp[cnt++][j] = board[i][j] * 2;
                i++;
            } else if (board[i][j]) {
                temp[cnt++][j] = board[i][j];
            }
        }
        if (board[n - 1][j]) {
            temp[cnt++][j] = board[n - 1][j];
        }
    }
    board = temp;
}

void downMove() {
    vector<vector<int>> temp(n, vector<int>(n, 0));
    for (int j = 0; j < n; j++) {
        int cnt = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (board[i][j]) {
                temp[cnt--][j] = board[i][j];
            }
        }
    }
    board = temp;
    temp.assign(n, vector<int>(n, 0));
    for (int j = 0; j < n; j++) {
        int cnt = n - 1;
        for (int i = n - 1; i > 0; i--) {
            if (board[i][j] && board[i][j] == board[i - 1][j]) {
                board[i - 1][j] = 0;
                temp[cnt--][j] = board[i][j] * 2;
                i--;
            } else if (board[i][j]) {
                temp[cnt--][j] = board[i][j];
            }
        }
        if (board[0][j]) {
            temp[cnt--][j] = board[0][j];
        }
    }
    board = temp;
}

void leftMove() {
    vector<vector<int>> temp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (board[i][j]) {
                temp[i][cnt++] = board[i][j];
            }
        }
    }
    board = temp;
    temp.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n - 1; j++) {
            if (board[i][j] && board[i][j] == board[i][j + 1]) {
                board[i][j + 1] = 0;
                temp[i][cnt++] = board[i][j] * 2;
                j++;
            } else if (board[i][j]) {
                temp[i][cnt++] = board[i][j];
            }
        }
        if (board[i][n - 1]) {
            temp[i][cnt++] = board[i][n - 1];
        }
    }
    board = temp;
}

void rightMove() {
    vector<vector<int>> temp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        int cnt = n - 1;
        for (int j = n - 1; j >= 0; j--) {
            if (board[i][j]) {
                temp[i][cnt--] = board[i][j];
            }
        }
    }
    board = temp;
    temp.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        int cnt = n - 1;
        for (int j = n - 1; j > 0; j--) {
            if (board[i][j] && board[i][j] == board[i][j - 1]) {
                board[i][j - 1] = 0;
                temp[i][cnt--] = board[i][j] * 2;
                j--;
            } else if (board[i][j]) {
                temp[i][cnt--] = board[i][j];
            }
        }
        if (board[i][0]) {
            temp[i][cnt--] = board[i][0];
        }
    }
    board = temp;
}

int maxBlock() {
    int max_block = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            max_block = max(max_block, board[i][j]);
        }
    }
    return max_block;
}

void backtracking(int cnt) {
    //print();
    if (cnt == 5) {
        ans = max(ans, maxBlock());
        return;
    }
    //상, 하, 좌, 우로 모두 이동시켜보기
    vector<vector<int>> temp = board;
    upMove();
    backtracking(cnt + 1);
    board = temp;

    downMove();
    backtracking(cnt + 1);
    board = temp;

    leftMove();
    backtracking(cnt + 1);
    board = temp;

    rightMove();
    backtracking(cnt + 1);
    board = temp;
}

/**
 * [2048]
 *
 * - 최대 5번을 이동시키는 모든 경우를 구한 후, 가장 큰 블록 찾는 문제 - 백트래킹 탐색
 * -
 */

int main() {
    //입력
    cin >> n;
    board.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    //연산
    backtracking(0);

    //출력
    cout << ans;
    return 0;
}