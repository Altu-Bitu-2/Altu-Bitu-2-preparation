#include <string>
#include <vector>

using namespace std;

vector<vector<vector<bool>>> board;

bool validate(int n, int x, int y, int p) {
    if (p == 0) {
        if (y == 0) {
            return true;
        }
        if (x - 1 >= 0 && board[x - 1][y][1]) {
            return true;
        }
        if (board[x][y][1]) {
            return true;
        }
        if (y - 1 >= 0 && board[x][y - 1][0]) {
            return true;
        }
    } else {
        if (y - 1 >= 0 && board[x][y - 1][0]) {
            return true;
        }
        if (x + 1 <= n && y - 1 >= 0 && board[x + 1][y - 1][0]) {
            return true;
        }
        if (x - 1 >= 0 && x + 1 <= n && board[x - 1][y][1] && board[x + 1][y][1]) {
            return true;
        }
    }
    return false;
}

void del(int n, int x, int y, int p) {
    board[x][y][p] = false;
    vector<int> dx = {-1, 0, 1};
    vector<int> dy = {-1, 0, 1};
    bool check = false;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int nx = x + dx[i];
            int ny = y + dy[j];
            if (nx < 0 || ny < 0 || nx > n || ny > n) {
                continue;
            }
            for (int k = 0; k < 2; k++) {
                if (board[nx][ny][k]) {
                    if (!validate(n, nx, ny, k)) {
                        check = true;
                        break;
                    }
                }
            }
            if (check) {
                break;
            }
        }
        if (check) {
            break;
        }
    }
    if (check) {
        board[x][y][p] = true;
    }
}

void simulation(int n, vector<vector<int>> &build_frame) {
    for (int i = 0; i < build_frame.size(); i++) {
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int p = build_frame[i][2];
        int cmd = build_frame[i][3];
        if (cmd == 1) { //설치
            if (validate(n, x, y, p)) {
                board[x][y][p] = true;
            }
        } else { //삭제
            del(n, x, y, p);
        }
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    board.assign(n + 1, vector<vector<bool>>(n + 1, vector<bool>(2, false)));
    simulation(n, build_frame);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k < 2; k++) {
                if (board[i][j][k] == false) {
                    continue;
                }
                answer.push_back({i, j, k});
            }
        }
    }
    return answer;
}