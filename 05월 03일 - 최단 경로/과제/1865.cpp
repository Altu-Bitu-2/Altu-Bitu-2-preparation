#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
typedef tuple<int, int, int> tp;
typedef long long ll;
const int INF = 5e6; //최대 n-1개의 간선을 지나게 됨 -> n * (가중치 최대값)

vector<ll> bellmanFord(int start, int n, int m, vector<tp> &edges) {
    //최솟값 갱신하는 과정에서 언더플로우 일어날 수 있음
    vector<ll> dist(n + 1, INF);

    //시작 정점 초기화
    dist[start] = 0;
    for (int i = 1; i <= n; i++) {
        bool flag = true; //더 이상 반복문을 실행할 필요가 없는지 확인 (갱신 확인)
        for (int j = 0; j < m; j++) {
            //s->d인 간선의 가중치가 w
            int s = get<0>(edges[j]);
            int d = get<1>(edges[j]);
            int w = get<2>(edges[j]);

            if (dist[s] == INF) { //아직 시작점에서 s로 가는 경로가 발견되지 않았으므로 갱신할 수 없음
                continue;
            }
            ll weight = dist[s] + w;
            if (weight < dist[d]) {
                dist[d] = weight;
                flag = false;
                if (i == n) { //n번째 갱신이었다면 -> 음의 사이클
                    return {-1};
                }
            }
        }
        if (flag) { //더 이상 갱신되지 않았다면 더 탐색할 필요 없음
            break;
        }
    }
    return dist;
}

/**
 * [웜홀]
 *
 *
 */

int main() {
    int tc, n, m, w, s, e, t;

    //입력
    cin >> tc;
    while (tc--) {
        cin >> n >> m >> w;
        vector<tp> edges;
        int edge_cnt = m * 2 + w;
        while (m--) {
            cin >> s >> e >> t;
            edges.push_back({s, e, t});
            edges.push_back({e, s, t});
        }
        while (w--) {
            cin >> s >> e >> t;
            edges.push_back({s, e, -t});
        }
        string ans = "NO";
        for (int i = 1; i <= n; i++) {
            vector<ll> dist = bellmanFord(i, n, edge_cnt, edges);
            if (dist[0] == -1) {
                ans = "YES";
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}