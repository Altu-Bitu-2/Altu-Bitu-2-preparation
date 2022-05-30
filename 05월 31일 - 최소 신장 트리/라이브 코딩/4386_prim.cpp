#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

const int INF = 1e3 + 1;
typedef pair<double, int> ci;

double prim(int n, int start, vector<vector<ci>> &graph) {
    double sum = 0; //간선 비용의 합
    priority_queue<ci, vector<ci>, greater<>> pq;
    vector<bool> visited(n, false); //정점 방문 여부 (다익스트라와 달리 프림에선 필요!)
    vector<int> dist(n, INF);   //각 정점까지의 비용 (없어도 상관없으나, 사용하면 메모리를 좀 더 아낄 수 있음)

    //초기화
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto[curr_w, curr] = pq.top();
        pq.pop();

        if (visited[curr]) { //이미 확인했던 정점
            continue;
        }
        visited[curr] = true;  //방문 처리
        sum += curr_w;  //MST 간선 가중치 총 합에 더해줌

        for (auto[next_w, next]: graph[curr]) {
            if (!visited[next] && dist[next] > next_w) {  //미방문 정점이면서 더 짧은 가중치가 등장한 경우
                dist[next] = next_w;
                pq.push({next_w, next});
            }
        }
    }

    return sum;
}

int main() {
    int n;
    double x, y;
    // 입력
    cin >> n;
    vector<vector<ci>> graph(n + 1, vector<ci>(0));
    vector<pair<double, double>> star;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        for (int j = 0; j < i; j++) {
            //임의의 두 별에 대한 거리(간선) 모두 구하기
            double dx = x - star[j].first;
            double dy = y - star[j].second;
            double dist = sqrt(dx * dx + dy * dy);
            graph[i].push_back({dist, j});  //무방향 그래프
            graph[j].push_back({dist, i});
        }
        star.push_back({x, y});
    }

    //연산 & 출력
    cout << fixed;  // 고정된 소수점 자리로 출력할 것을 선언
    cout.precision(2);  // 소수점 2번째자리로 정확도를 설정
    cout << prim(n, 1, graph);
    return 0;
}