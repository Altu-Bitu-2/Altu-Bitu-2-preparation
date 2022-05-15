#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> graph;  // 인접 리스트
vector<bool> visited;   // 방문 체크
bool is_tree;   // 트리인지 여부 저장하는 변수

// 결과 출력 함수
void printResult(int tc, int tree_cnt) {
    cout << "Case " << tc << ": ";

    switch (tree_cnt) {
        case 0:
            cout << "No trees.\n";
            break;
            0
        case 1:
            cout << "There is one tree.\n";
            break;
        default:
            cout << "A forest of " << tree_cnt << " trees.\n";
    }
    return;
}

void dfs(int curr, int prev) {
    // 이미 방문한 노드를 다시 방문했다면 사이클이 발생한 것
    if (visited[curr]) {
        is_tree = false;
        return;
    }
    visited[curr] = true;   // 방문체크

    for (int next: graph[curr]) {
        if (next == prev) {
            continue;
        }
        dfs(next, curr);
    }
    return;
}

int main() {
    int n, m, a, b;
    int tc = 0;
    while (cin >> n >> m) {
        // 종료 조건
        if (n == 0 && m == 0) {
            break;
        }

        IN
        // 초기화
        tc++;
        graph.assign(n + 1, vector<int>(0));
        visited.assign(n + 1, false);

        // 입력
        while (m--) {
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        // 모든 노드에 대해 방문하며 트리의 수 카운트
        int tree_cnt = 0;

        for (int i = 1; i <= n; i++) {
            is_tree = true;
            dfs(i, 0);
            if (is_tree) {
                tree_cnt++;
            }
        }

        // 출력
        printResult(tc, tree_cnt);
    }
    return 0;
}