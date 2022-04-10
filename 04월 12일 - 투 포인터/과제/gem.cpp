#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

//같은 위치에서 시작하여 같은 방향으로 이동하는 투 포인터
//모든 보석 종류를 포함하는 가장 짧은 구간 리턴
vector<int> gemListTwoPointer(int left, int right, int gem_size, vector<string> &gems) {
    int size = gems.size(); //전체 보석 개수
    vector<int> ans = {1, size};
    map<string, int> m;

    m[gems[left]]++; //초기 구간
    while (left <= right && right < size) {
        if (m.size() == gem_size) { //모든 종류의 보석이 있음 -> 구간 짧게
            if (right - left < ans[1] - ans[0]) {
                ans = {left + 1, right + 1};
            }
            m[gems[left++]]--;
            if (m[gems[left - 1]] == 0) { //더이상 이 보석이 없다면 제거
                m.erase(gems[left - 1]);
            }
        } else if (m.size() < gem_size) { //모든 종류의 보석이 있는게 아니라면
            right++; //구간을 길게하기 위해 right 이동
            if (right == size) { //런타임 에러 방지
                break;
            }
            m[gems[right]]++;
        }
    }
    return ans;
}

vector<int> solution(vector<string> gems) {
    vector<int> answer;

    set<string> unique_gem;
    for (int i = 0; i < gems.size(); i++) {
        unique_gem.insert(gems[i]);
    }
    int gem_size = unique_gem.size(); //보석의 종류

    answer = gemListTwoPointer(0, 0, gem_size, gems);
    return answer;
}

/**
 * [보석 쇼핑]
 *
 * 1. set을 활용해 보석의 종류 구함 (중복 x)
 * 2. 같은 위치에서 시작해서 같은 방향으로 이동하면서 모든 종류 포함하는 구간의 최소값 찾아감 (투 포인터)
 *    - 이때, 구간 안에 보석 종류의 존재 여부를 map을 통해서 관리
 */

int main() {
    //입력
    vector<string> gems = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};

    //연산
    vector<int> ans = solution(gems);

    //출력
    cout << ans[0] << ' ' << ans[1];
}