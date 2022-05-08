#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
typedef tuple<int, int, int> tp;
const int INF = 5e6; //최대 n-1개의 간선을 지나게 됨 -> n * (가중치 최대값)

vector<int> bellmanFord(int start, int n, vector<tp> &edges) {
    vector<int> dist(n + 1, INF);

    dist[start] = 0;
    for (int i = 1; i <= n; i++) {
        bool flag = true;
        for (int j = 0; j < edges.size(); j++) {
            int s = get<0>(edges[j]);
            int d = get<1>(edges[j]);
            int w = get<2>(edges[j]);

            if (dist[s] == INF) {
                continue;
            }
            int weight = dist[s] + w;
            if (weight < dist[d]) {
                dist[d] = weight;
                flag = false;
                if (i == n) {
                    return {INF + 1}; //음의 사이클이 생겼음을 INF+1로 나타냄
                }
            }
        }
        if (flag) {
            break;
        }
    }
    return dist;
}

/**
 * [웜홀]
 *
 * 벨만-포드 문제
 *
 * 시간이 되돌아가서 출발 지점에 도착하는 경우 = 음의 사이클이 생긴 경우
 *
 * 특별히 시작점이 주어지지 않았으므로, 음의 사이클이 생긴 경우를 모든 점을 시작점으로 고려해서 판단해야 함
 * 이때, 모든 정점마다 벨만-포드를 돌리면 원래라면 시간초과라 "임의의 가짜 정점"을 만들어서 구함!
 * => 가짜 정점 0을 만들어서 모든 정점과 가중치 0으로 연결시킨 후, 가짜 정점 0에서 벨만-포드 돌림
 * 이렇게 되면 모든 정점을 시작 정점으로 고려하게 됨!
 */

int main() {
    int tc, n, m, w, s, e, t;

    //입력
    cin >> tc;
    while (tc--) {
        cin >> n >> m >> w;
        vector<tp> edges; //간선의 수
        while (m--) { //도로 -> 무방향
            cin >> s >> e >> t;
            edges.push_back({s, e, t});
            edges.push_back({e, s, t});
        }
        while (w--) { //웜홀 -> 방향
            cin >> s >> e >> t;
            edges.push_back({s, e, -t});
        }

        //가짜 정점 생성
        for (int i = 1; i <= n; i++) {
            edges.push_back({0, i, 0});
        }

        //연산
        vector<int> dist = bellmanFord(0, n + 1, edges);

        //출력
        if (dist[0] == INF + 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}