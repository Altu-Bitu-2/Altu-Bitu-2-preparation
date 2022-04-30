#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int dfsIter(int n, vector<vector<int>> &adj_list) {
    int count = 0;
    stack<int> stk;
    vector<bool> visited(n+1, false);

    // 수를 세는 방법
    // 1. 스택에 넣으면서 카운트
    // 2. 스택에서 제거할 때 카운트
    // 3. 나중에 방문 배열을 카운트

    stk.push(1);
    visited[1] = true;

    while (!stk.empty()){
        int curr = stk.top();
        stk.pop();  // 스택에서 값 제거 -> 2번으로 할거면 여기서 카운트
        // 주의 -> 1번 컴퓨터도 카운트에 들어가므로 return count -1;

        // curr에 연결되어 있는 모든 인접 정점(컴퓨터)에 대해
        for (auto next:adj_list[curr]){
            if (visited[next]) {
                continue;
            }
            visited[next] = true;
            stk.push(next); // 스택에 삽입 -> 1번으로 할거면 여기서 카운트
            count++;
        }
    }
    return count;
}

int bfs(int n, vector<vector<int>> &adj_list) {
    int count = 0;
    queue<int> que;
    vector<bool> visited(n + 1, false);

    // 수를 세는 방법
    // 1. 큐에 넣으면서 카운트
    // 2. 큐에서 제거할 때 카운트
    // 3. 나중에 방문 배열을 카운트

    que.push(1);
    visited[1] = true;

    while (!que.empty()) {
        int curr = que.front();
        que.pop(); // 큐에서 값 제거 -> 2번으로 할거면 여기서 카운트
        // 주의 -> 1번 컴퓨터도 카운트에 들어가므로 return count -1;

        // curr에 연결되어 있는 모든 인접 정점(컴퓨터)에 대해
        for (auto next: adj_list[curr]) {
            if (visited[next]) {
                continue;
            }
            visited[next] = true;
            que.push(next); // 큐에 삽입 -> 1번으로 할거면 여기서 카운트
            count++;
        }
    }
    return count;
}

int main() {
    int n, m, a, b;
    // 입력
    cin >> n >> m;
    // 인접 리스트 선언
    vector<vector<int>> adj_list(n + 1, vector<int>());
    while (m--) {
        cin >> a >> b;
        // 컴퓨터는 "서로" 연결되어 있으므로 양방향 정보 모두 표기
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    // 연산 + 출력
//    cout << bfs(n, adj_list);
    cout << dfsIter(n, adj_list);

    return 0;
}