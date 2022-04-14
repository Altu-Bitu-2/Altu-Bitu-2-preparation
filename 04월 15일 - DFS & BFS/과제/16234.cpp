#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

//상, 하, 좌, 우
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
vector<vector<int>> board; //각 나라 인구

//각 연합의 인구 수만큼 인구 이동하는 함수
bool peopleMove(int n, int population, vector<vector<int>> &visited) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j] == 1) {
                visited[i][j] = -1;
                board[i][j] = population;
            }
        }
    }
    return true; //인구 이동 했음을 나타냄
}

ci bfs(int n, int l, int r, int cr, int cc, vector<vector<int>> &visited) {
    queue<ci> q;
    q.push({cr, cc});
    visited[cr][cc] = 1;

    int sum = board[cr][cc], cnt = 1;
    while (!q.empty()) {
        cr = q.front().first;
        cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc]) {
                continue;
            }
            int diff = abs(board[nr][nc] - board[cr][cc]);
            if (diff >= l && diff <= r) { //국경선 열림
                q.push({nr, nc});
                visited[nr][nc] = 1;
                sum += board[nr][nc];
                cnt++;
            }
        }
    }
    if (cnt == 1) { //국경선이 열린 나라가 없다면
        visited[cr][cc] = -1;
        return {-1, -1};
    }
    return {sum, cnt};
}

int simulation(int n, int l, int r) {
    int day = 0;
    while (true) {
        vector<vector<int>> visited(n, vector<int>(n, 0));
        bool is_move = false; //인구 이동 했는지 체크
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j]) { //이미 탐색한 나라라면
                    continue;
                }
                ci info = bfs(n, l, r, i, j, visited);
                if (info.first != -1) {
                    is_move = peopleMove(n, info.first / info.second, visited);
                }
            }
        }
        if (!is_move) {
            return day;
        }
        day++;
    }
}

/**
 * [인구 이동]
 *
 * 모든 나라에 대해서 처음 탐색하는 나라면 bfs 탐색 시작
 *   - bfs 탐색을 통해 국경선 오픈할 수 있는 나라 찾고 연합으로 묶기 -> 연합의 인구수와 연합을 이루고 있는 칸의 개수 리턴
 *   - 해당 연합의 인구 수 바꾸기 (인구 이동)
 *
 * 국경선 오픈할 수 있는 나라가 한 개도 없으면 -> 인구 이동 못함 -> break
 *
 * visited: 탐색 여부 저장 & 연합 구분
 *    0: 탐색 안함
 *    1: 탐색 함 & 연합
 *   -1: 이미 인구 이동이 끝난 연합
 *   국경선 오픈하는 나라 없을 때, 연합이 아니므로 1을 다시 -1로 바꿔줘야 함을 주의
 */

int main() {
    int n, l, r;

    //입력
    cin >> n >> l >> r;
    board.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    //연산 & 출력
    cout << simulation(n, l, r);
    return 0;
}