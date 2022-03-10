#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 결과값을 보고 처음 도출 -> 기술을 모두 반대로 쓰자!
 * 1. 제일 위의 카드 앞에 넣기
 * 2. 제일 위의 카드 앞에서 두번째에 넣기
 * 3. 제일 위의 카드 뒤에 넣기
 */

int main() {
    int n;

    //입력
    cin >> n;
    vector<int> cmd(n + 1, 0);
    deque<int> dq;
    for (int i = 1; i <= n; i++) { //입력
        cin >> cmd[i];
    }
    reverse(cmd.begin() + 1, cmd.end());
    for (int i = 1; i <= n; i++) {
        switch (cmd[i]) {
            case 1:
                dq.push_front(i);
                break;
            case 2: {
                int x = dq.front();
                dq.pop_front();
                dq.push_front(i);
                dq.push_front(x);
                break;
            }
            case 3:
                dq.push_back(i);
                break;
        }
    }
    while (!dq.empty()) {
        cout << dq.front() << ' ';
        dq.pop_front();
    }
    return 0;
}