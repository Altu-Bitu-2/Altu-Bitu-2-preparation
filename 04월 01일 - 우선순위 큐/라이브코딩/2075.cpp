#include <iostream>
#include <queue>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n;
    int size = n * n;

    // 최소힙 생성 - sort와 반대
    priority_queue<int, vector<int>, greater<>> pq;

    while (size--) {
        cin >> x;
        if (pq.size() < n) {    // pq의 크기가 n보다 작으면 바로 삽입 (처음 n개)
            pq.push(x);
        }
        // pq에 존재하는 n개의 합 중 가장 작은 값 (min heap의 top)보다 커야 pq에 들어갈 수 있음
        else if (x > pq.top()) {
            pq.pop();
            pq.push(x);
        }
    }

    cout << pq.top();
    return 0;
}