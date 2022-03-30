#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    vector<int> clothes(n + 2, 1);  // 예외 처리 (인덱스 에러 나지 않도록)

    for (auto i: lost) {    // 체육복을 잃어버린 학생
        clothes[i]--;
    }
    for (auto i: reserve) { // 여분 옷을 가져온 학생
        clothes[i]++;
    }
    for (int i = 1; i <= n; i++) {
        if (clothes[i]) {   // 체육복 있으면
            continue;
        }
        if (clothes[i - 1] == 2) { // 왼쪽 학생에게 체육복 빌릴 수 있으면
            clothes[i]++;
            clothes[i - 1]--;
        } else if (clothes[i + 1] == 2) { // 오른쪽 학생에게 체육복 빌릴 수 있으면
            clothes[i]++;
            clothes[i + 1]--;
        }
    }
    for (int i=1; i<=n; i++) {
        if (clothes[i]) {
            answer++;
        }
    }
    return answer;
}

//프로그래머스 예제 테스트할 수 있는 메인함수
int main() {
    vector<int> lost = {2, 4};
    vector<int> reserve = {1, 3, 5};
    int n = 5;

    cout << solution(n, lost, reserve);

    return 0;
}