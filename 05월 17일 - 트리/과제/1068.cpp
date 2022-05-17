#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;

//리프 노드의 수
int leafCnt(int node) {
    if (tree[node].empty()) { //리프 노드
        return 1;
    }
    int cnt = 0;
    for (int i = 0; i < tree[node].size(); i++) {
        cnt += leafCnt(tree[node][i]);
    }
    return cnt;
}

int main() {
    int n, par, root, erase_node;

    //입력
    cin >> n;
    tree.assign(n, vector<int>(0));
    for (int i = 0; i < n; i++) {
        cin >> par;
        if (par == -1) {
            root = i;
            continue;
        }
        tree[par].push_back(i);
    }
    cin >> erase_node;

    //총 리프 노드의 개수 먼저 구함
    int total_leaf = leafCnt(root);

    //정점 지움으로써 리프 노드 1개 늘어난 경우
    for (int i = 0; i < n; i++) {
        if (tree[i].size() == 1 && tree[i][0] == erase_node) {
            total_leaf++;
        }
    }

    //지우는 정점의 리프 노드 개수
    int erase_leaf = leafCnt(erase_node);

    //출력
    cout << total_leaf - erase_leaf;
    return 0;
}