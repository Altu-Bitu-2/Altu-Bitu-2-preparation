#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//휴게소 몇 개 설치하는지 구하는 함수
int cntRest(int dist, int l, vector<int> &rest) {
    int cnt = 0;

    if (rest.size() == 0) { //처음 휴게소 아예 없는 경우 예외 처리
        return (l - 1) / dist;
    }
    cnt += (rest[0] - 1) / dist;
    for (int i = 1; i < rest.size(); i++) {
        cnt += (rest[i] - rest[i - 1] - 1) / dist;
    }
    cnt += (l - rest[rest.size() - 1] - 1) / dist;
    return cnt;
}

//휴게소가 없는 구간의 최댓값 중 최솟값 구하는 함수 -> lower bound
int lowerSearch(int left, int right, int m, int l, vector<int> &rest) {
    while (left <= right) {
        int mid = (left + right) / 2; //최댓값 설정
        int cnt = cntRest(mid, l, rest); //몇 개 휴게소 설치하는지

        if (cnt > m) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

/**
 * [휴게소 세우기]
 *
 * M개의 휴게소를 짓고 난 후에 휴게소가 없는 구간의 최댓값의 최솟값은?
 * -> 휴게소가 없는 구간의 최댓값이 k(임의의 수)일 때, M개의 휴게소를 지을 수 있는가?
 *
 * left: 휴게소가 없는 구간의 최솟값 -> 1
 * right: 휴게소가 없는 구간의 최댓값 -> l - 1
 *
 * 휴게소 구간의 최댓값이 주어졌을 때, 몇 개의 휴게소 짓는지 구하는 방법
 * -> 처음 존재하는 휴게소 구간을 최대값으로 나누면 그 몫이 최대 구간이 최대값이 되도록 현재 구간 안에 설치해야 하는 휴게소 개수!
 */

int main() {
    int n, m, l;

    //입력
    cin >> n >> m >> l;
    vector<int> rest(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> rest[i];
    }

    //연산
    sort(rest.begin(), rest.end());

    //연산 & 출력
    cout << lowerSearch(1, l - 1, m, l, rest);
    return 0;
}