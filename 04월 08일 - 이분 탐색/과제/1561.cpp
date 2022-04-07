#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
const ll INF = 6e10;

ll peopleOrder(ll t, vector<int> &rides) {
    ll order = 0;
    for (int i = 1; i < rides.size(); i++) {
        order += (t / rides[i] + 1);
    }
    return order;
}

ll lowerSearch(ll left, ll right, ll target, vector<int> &rides) {
    while (left <= right) {
        ll mid = (left + right) / 2;
        ll order = peopleOrder(mid, rides);

        if (order >= target) { //줄의 마지막 아이보다 더 뒤에 있는 아이라면
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left - 1;
}

/**
 * [놀이 공원]
 *
 * 놀이기구가 모두 비어 있는 상태에서 첫 번째 아이가 놀이기구에 탑승한다고 할 때, 줄의 마지막 아이가 타게 되는 놀이기구의 번호
 * f(t) += (t/num[i] + 1)
 *
 * t에 대해 이분탐색하다가 n 이 범위 안이면 break
 */

int main() {
    int n, m;

    //입력
    cin >> n >> m;
    vector<int> rides(m + 1, 0);
    for (int i = 1; i <= m; i++) {
        cin >> rides[i];
    }

    if (n <= m) {
        cout << n;
        return 0;
    }

    //그 전 시간대
    int ans = 1;
    ll prev_time = lowerSearch(0, INF, n, rides);
    ll prev_people = peopleOrder(prev_time, rides);

    for (int i = 1; i <= m; i++) {
        if ((prev_time + 1) % rides[i] == 0) { //추가
            prev_people++;
            if (prev_people == n) {
                ans = i;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}