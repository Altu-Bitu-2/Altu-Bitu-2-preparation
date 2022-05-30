#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;
typedef tuple<int, int, int> tp;

vector<int> parent;

// Find 연산
int findParent(int x) {
    if (parent[x] < 0) { //값이 음수면 루트 정점
        return x;
    }
    return parent[x] = findParent(parent[x]); //그래프 압축하며 루트 정점 찾기
}

// union 연산
bool unionNodes(int x, int y) {
    int px = findParent(x);
    int py = findParent(y);

    if (px == py) {
        return false;
    }

    if (px < py) { //새로운 루트 px
        parent[px] += parent[py];
        parent[py] = px;
    } else { //새로운 루트 py
        parent[py] += parent[px];
        parent[px] = py;
    }
    return true;
}

int kruskal(int v, vector<tp> &vertex) {
    int sum = 0, cnt = 0;

    for (auto[w, n1, n2]: vertex) {
//        w = get<0>(vertex[i]);
//        n1 = get<1>(vertex[i]);
//        n2 = get<2>(vertex[i]);
        if (!unionNodes(n1, n2)) { //사이클이 생기는 경우
            continue;
        }
        sum += w;
        cnt++;
        if (cnt == v-1){ //간선 다 찾은 경우
            return sum;
        }
    }

    return sum;
}

int main() {
    int v, e, a, b, c;
    // 입력
    cin >> v >> e;
    parent.assign(v + 1, -1);
    vector<tp> vertex;

    while (e--) {
        cin >> a >> b >> c;
        vertex.push_back({c, a, b});
    }
    sort(vertex.begin(), vertex.end());

    // 연산 & 출력
    cout << kruskal(v, vertex);
    return 0;
}