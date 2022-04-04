#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ci;

int getMaxCount(int n, vector<ci> &meetings) {
    int count = 0;  // 회의 개수
    int prev_end = 0;   // 직전 회의의 끝나는 시간
    for (int i = 0; i < n; i++) {
        auto[end, start] = meetings[i]; // c++17부터 지원
                                        // int start = meetings[i].second
                                        // int end = meetings[i].first 와 같은 의미
        if (start >= prev_end) {    // 직전 회의가 끝나는 시간보다 같거나 늦게 시작해야 함
            count++;
            prev_end = end;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<ci> meetings(n, {0, 0});
    // 이후 정렬을 할 때,
    // 1. 빨리 끝나는 순서대로
    // 2. 빨리 시작하는 순서대로
    // 따라서 first에 끝나는 시간, second에 시작하는 시간 저장!

    for (int i = 0; i < n; i++) {
        cin >> meetings[i].second >> meetings[i].first;
    }
    // 빨리 끝나는 순서대로, 빨리 시작하는 순서대로 정렬
    sort(meetings.begin(), meetings.end());

    cout << getMaxCount(n, meetings);
    return 0;
}