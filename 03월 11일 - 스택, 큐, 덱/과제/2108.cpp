//
// Created by JIYOUNG.P on 2022-03-10.
//

#include <iostream>
#include <vector>
#include <algorithm>    // sort() 사용
#include <numeric>      // accumulate() 사용
#include <cmath>        // floor() || round() 사용

using namespace std;

typedef pair<int, int> ci;  // pair<int, int>에 ci라는 별칭 부여

// 비교함수
bool cmp(const ci &a, const ci &b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

int findMode(int n, vector<int> &arr) {
    // 정렬된 벡터에서 최빈값을 찾아 반환하고, 만약 최빈값이 여러개라면 두번째로 작은 값을 반환하는 함수
    vector<ci> count;   // 정수의 개수와 해당 정수 값을 pair로 묶어서 저장하는 벡터
    // first: 개수, second: 값

    int current_idx = 0;    // 현재의 인덱스를 저장하는 변수
    count.push_back({1, arr[0]});   // 첫번째 값을 입력하여 for문에서 index 에러 방지

    for (int i = 1; i < n; i++) {
        // 만약 직전 값과 같은 값이라면
        if (arr[i] == arr[i - 1]) {
            // 개수 +1
            count[current_idx].first++;
        } else {
            // 그렇지 않다면, 새로운 값을 count 벡터에 삽입
            count.push_back({1, arr[i]});
            current_idx++;
        }
    }

    // 만약 값이 한 종류라면, 바로 리턴 -> 아래에서 인덱스 에러 방지
    if (current_idx == 0) {
        return arr[0];
    }

    // 정렬
    // 1. 개수(first)에 대해 내림차순
    // 2. 값(second)에 대해 오름차순
    sort(count.begin(), count.end(), cmp);

    // 최빈 값이 여러개인지 확인
    if (count[0].first == count[1].first) {
        return count[1].second;
    }
    return count[0].second;
}

int main() {
    int n;
    cin >> n;

    // n 최대 500,000 * 입력값 최대 4,000 = 2,000,000,000 <- int 범위 안
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    // 산술평균 구하기, 나눠주기 위해서 float형으로 받아야 합니다.
    float sum = accumulate(arr.begin(), arr.end(), 0);
    cout << floor(sum / n + 0.5) << '\n';

    // 중앙값 구하기
    cout << arr[n / 2] << '\n';

    // 최빈값 구하기
    cout << findMode(n, arr) << '\n';

    // 범위 구하기
    cout << arr[n - 1] - arr[0] << '\n';
}