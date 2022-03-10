#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> simulation(int k, queue<int> &q) {
    vector<int> result;
    int cnt = 0;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cnt++;
        if (cnt == k) { //k번째 pop하는 원소라면
            result.push_back(x); //정답 벡터에 추가
            cnt = 0; //카운트 초기화
            continue;
        }
        q.push(x); //pop한 원소 다시 push
    }
    return result;
}

/**
 * 큐 초기화 후 pop, push 반복
 * k번째 pop일 경우 정답 벡터에 push_back
 */

int main() {
    int n, k;
    queue<int> q;

    //입력
    cin >> n >> k;
    for (int i = 1; i <= n; i++) { //큐 초기화
        q.push(i);
    }
    //연산
    vector<int> result = simulation(k, q);
    //출력
    cout << '<';
    for (int i = 0; i < result.size() - 1; i++) {
        cout << result[i] << ", ";
    }
    cout << result[result.size() - 1] << '>';
    return 0;
}