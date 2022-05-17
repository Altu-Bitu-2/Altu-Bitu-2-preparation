#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e9;

int n, ans = INF;
vector<bool> is_ward, visited;
vector<int> people;
vector<vector<int>> graph;

int dfs(int curr, bool state) {
    if (visited[curr]) {
        return 0;
    }
    visited[curr] = true;
    int cnt = people[curr];
    for (int i = 0; i < graph[curr].size(); i++) {
        if (is_ward[graph[curr][i]] == state) {
            cnt += dfs(graph[curr][i], state);
        }
    }
    return cnt;
}

void backtracking(int cnt) {
    if (cnt == n + 1) {
        visited.assign(n + 1, false);
        int curr = 0;
        int p1 = dfs(1, true);
        for (int i = 1; i <= n; i++) {
            if (!is_ward[i]) {
                curr = i;
            }
            if (visited[i] != is_ward[i]) {
                return;
            }
        }
        int p2 = dfs(curr, false);
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                return;
            }
        }
        ans = min(ans, abs(p1 - p2));
        return;
    }
    for (int i = 0; i < 2; i++) {
        is_ward[cnt] = i;
        backtracking(cnt + 1);
        is_ward[cnt] = false;
    }

}

/**
 * [게리맨더링]
 *
 * 백트래킹으로 구역을 나누는 모든 경우의 수 구하기 - 백트래킹
 * 각 경우마다 나눈 두 구역이 조건을 만족하는지(구역 내 정점은 모두 연결) 확인 - dfs
 */

int main() {
    int c, a;

    //입력
    cin >> n;
    people.assign(n + 1, 0);
    graph.assign(n + 1, vector<int>(0)); //인접리스트
    is_ward.assign(n + 1, false);
    visited.assign(n + 1, false);
    for (int i = 1; i <= n; i++) {
        cin >> people[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> c;
        while (c--) {
            cin >> a;
            graph[i].push_back(a);
            graph[a].push_back(i);
        }
    }

    //연산
    is_ward[1] = true; //1번 고정
    backtracking(2);

    //출력
    cout << (ans == INF ? -1 : ans);
    return 0;
}