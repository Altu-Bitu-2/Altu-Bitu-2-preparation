#include <iostream>
#include <vector>

using namespace std;

vector<int> possibleWeight(int left, int right, int g) {
    vector<int> ans;
    while (left <= right) {
        int diff = right * right - left * left;

        if (right - left == 1 && diff > g) {
            break;
        }
        if (diff <= g) {
            if (diff == g) {
                ans.push_back(right);
            }
            right++;
        } else {
            left++;
        }
    }
    return ans;
}

/**
 * [다이어트]
 *
 * left: 성원이가 기억하고 있던 몸무게
 * right: 성원이의 현재 몸무게
 *
 * 같은 위치에서 시작해서 점점 증가하는 투 포인터로 풀이
 * 대신, left ~ right를 모두 고려하는 것이 아니라 left, right 포인터 값 자체만 고려
 *
 * !주의! 몸무게의 범위가 딱히 정해져 있지 않으므로, 종료 조건을 잘 세우는 것이 중요!
 *       -> 가장 인접한 몸무게 제곱근의 차이가 g를 넘으면 더 이상 탐색 불가
 */

int main() {
    int g;

    //입력
    cin >> g;

    //연산
    vector<int> ans = possibleWeight(1, 1, g);

    //출력
    if (!ans.size()) {
        cout << "-1";
        return 0;
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}