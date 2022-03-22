#include <iostream>
#include <vector>

using namespace std;

/*
 * 1. 총감독관은 반드시 1명
 * 2. 이에 따라 부독관이 필요 없는 시험장 존재
 * 3. 응시자의 수가 C로 나누어 떨어지지 않는다면...?
 * 4. 시험장의 개수, 응시자의 수가 최대인데, B와 C가 최소로 주어진다면...?
 * */

int main() {
    int n, b, c;

    // 입력
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> b >> c;

    // 시험장 최대 1,000,000 * 응시자 수 최대 1,000,000 = 1,000,000,000,000
    // b, c가 1이라면? -> answer 최댓값 1,000,000,000,000 -> long long
    long long answer = n;     // 각 시험장에 총 감독관 1명씩 배치

    for (int i = 0; i < n; i++) {
        int count = arr[i] - b;    // 총감독관이 감독할 수 있는 인원 사전에 제외
        if (count <= 0) {  // 총감독관 1명이면 충분
            continue;
        }

        answer += count / c;   // 남은 인원 수에 맞춰 부감독관 배치

        if (count % c != 0) {
            answer++;   // 나머지가 있으면 부감독관 한명 추가
        }
    }

    cout << answer;
    return 0;
}