#include <iostream>
#include <vector>

using namespace std;

/**
 * 매 게임 얻는 점수 내림차순 (동점있음)
 * 동점 처리 -> 가장 작은 등수
 * 새로운 점수가 랭킹 리스트에서 몇 등 하는지
 */

int main() {
    int n, new_score, p;

    //입력
    cin >> n >> new_score >> p;
    vector<int> ranking(p + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> ranking[i];
    }
    //연산
    int idx = 1;
    int ans = 1;
    while (ranking[idx] != 0 && new_score <= ranking[idx] && idx <= p) {
        if (new_score < ranking[idx]) {
            ans = idx;
            ans++;
        }
        idx++;
    }
    if (idx > p) {
        cout << "-1";
    } else {
        cout << ans;
    }
    return 0;
}