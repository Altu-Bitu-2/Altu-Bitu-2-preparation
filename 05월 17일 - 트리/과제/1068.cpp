#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;

//리프 노드의 수
int leafCnt(int node) {
    if (tree[node].empty()) {
        return 1;
    }
    int cnt = 0;
    for (int i = 0; i < tree[node].size(); i++) {
        cnt += leafCnt(tree[node][i]);
    }
    return cnt;
}

int eraseNode(int n, int &root, int &erase_node) {
    int total_leaf = leafCnt(root);
    int erase_leaf = leafCnt(erase_node);
    for (int i = 0; i < n; i++) {
        if (tree[i].size() == 1 && tree[i][0] == erase_node) {
            total_leaf++;
        }
    }
    return total_leaf - erase_leaf;
}

/**
 * [트리]
 *
 * - 전체 리프 노드의 개수에서 지우는 정점의 리프 노드 개수를 뺌
 * - 리프 노드의 개수는 dfs 탐색으로 구함 (특정 노드를 루트로 했을 때의 리프 노드 개수를 편하게 구할 수 있음)
 *
 * !주의! 지우는 정점이 해당 부모 노드의 유일한 자식 노드였을 경우, 해당 정점을 지우면 부모 노드가 리프 노드가 돼서 개수가 1 증가함을 주의
 * !주의! 루트 노드가 항상 0이 아님을 주의
 */

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

    //연산 & 출력
    cout << eraseNode(n, root, erase_node);
    return 0;
}