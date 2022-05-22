#include <vector>
#include <iostream>

using namespace std;
const int SIZE = 10;

vector<int> ryan(SIZE + 1, 0), apeach; //라이언과 어피치의 과녁 정보
vector<int> answer = {-1}; //라이언이 가장 큰 점수 차이로 우승하는 경우
int max_diff = 0; //가장 큰 점수 차이

bool cmp() {
    for (int i = SIZE; i >= 0; i--) {
        if (answer[i] > ryan[i]) {
            return false;
        } else if (answer[i] < ryan[i]) {
            return true;
        }
    }
}

int calcDiff() {
    int score_r = 0, score_a = 0;
    for (int i = 0; i <= SIZE; i++) {
        int score = SIZE - i;
        if (ryan[i] > apeach[i]) {
            score_r += score;
        } else if (ryan[i] < apeach[i]) {
            score_a += score;
        }
    }
    return score_r - score_a;
}

void backtracking(int cnt, int extra_arrows) {
    if (cnt == SIZE + 1 || extra_arrows == 0) { //(기저조건) 0점 과녁까지 탐색 or 남은 화살 없음
        ryan[SIZE] = extra_arrows; //화살 남아있을 수 있으므로
        int curr_diff = calcDiff();
        if (max_diff < curr_diff) {
            max_diff = curr_diff;
            answer = ryan;
        } else if (curr_diff != 0 && max_diff == curr_diff && cmp()) {
            answer = ryan;
        }
        return;
    }
    if (extra_arrows > apeach[cnt]) { //남은 화살으로 라이언이 점수를 얻을 수 있다면
        ryan[cnt] = apeach[cnt] + 1;
        backtracking(cnt + 1, extra_arrows - apeach[cnt] - 1);
        ryan[cnt] = 0;
    }
    backtracking(cnt + 1, extra_arrows);
}

vector<int> solution(int n, vector<int> info) {
    apeach = info; //백트래킹 탐색 편의를 위해 전역변수에 복사
    backtracking(0, n); //연산
    return answer;
}

/**
 * [양궁대회]
 *
 * 1. 가능한 모든 경우를 백트래킹 탐색을 통해 검사
 * -> 라이언이 과녁 점수를 얻어가려면 어피치보다 1개 더 쏘는 경우가 최적. 어피치보다 적게 화살 쏘는 건 점수 못 얻어가므로 어차피 의미가 없음.
 * -> 따라서 라이언이 각 과녁에 화살을 (어피치 화살 개수 + 1) or (0개) 로 쏘는 경우만 고려해서 모든 경우를 백트래킹으로 탐색
 *
 * 2. 가장 큰 점수 차이가 동일한 경우, 낮은 점수를 더 많이 맞힌 경우를 조건문으로 따로 해결
 * -> 단순 탐색하다가 갱신되는 값으로 하면 코너케이스 생김
 * -> 직접 0점 과녁부터 개수 비교해서 가장 낮은 점수를 더 많이 맞힌 경우 선택할 수 있도록 함
 *
 * !주의! 0번 인덱스가 10점 과녁임을 주의
 */

int main() {
    int n = 5;
    vector<int> info = {2, 1, 1, 1, 0, 0, 0, 0, 0, 0};
    vector<int> result = solution(n, info);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';
    }
    return 0;
}