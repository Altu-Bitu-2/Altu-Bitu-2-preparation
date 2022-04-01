#include <iostream>
#include <queue>

using namespace std;

struct cmp {
    // sort의 비교함수와 반대로 작성!
    // 우선순위 큐의 비교함수는 두번째로 온 인자가 더 우선순위가 높다고 생각하고 작성하면 편하다
    // 즉, x2가 x1보다 우선순위가 더 높다!!
    bool operator()(const int &x1, const int &x2) {
        // 둘의 절댓값이 다르다면
        if (abs(x2) != abs(x1)) {
            return abs(x2) < abs(x1); // x2의 절댓값이 x1의 절댓값보다 작다
        }
        // 둘의 절댓값이 같다면
        return x2 < x1;     // x2가 x1보다 작을 것
    }
};

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    // 입력
    cin >> n;
    // 우선순위 큐 선언
    priority_queue<int, vector<int>, cmp> pq;

    cin >> x;
    while (n--) {
        // 출력 + 삭제
        if (x == 0) {
            if (pq.empty()) {
                cout << "0\n";
            } else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        } else { // 삽입
            pq.push(x);
        }
    }
    return 0;
}