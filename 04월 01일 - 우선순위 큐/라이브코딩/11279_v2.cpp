#include <iostream>
#include <queue>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    cin >> n;

    // heap 초기화
    priority_queue<int> max_heap;

    while (n--) {
        cin >> x;
        if (x == 0) {
            if (max_heap.empty()) {
                cout << "0\n";
            } else {
                cout << max_heap.top() << '\n';
                max_heap.pop();  // 삭제
            }
        } else {
            max_heap.push(x);    // 삽입
        }
    }
    return 0;
}