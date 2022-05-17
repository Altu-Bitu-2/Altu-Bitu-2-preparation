#include <vector>
#include <iostream>

using namespace std;
const int SIZE = 10;

vector<int> apeach, lion(SIZE + 1, 0); //어피치와 라이언의 과녁 정보
vector<int> answer = {-1}; //라이언이 가장 큰 점수 차이로 이기는 과녁 정보
int diff = 0; //점수 차이

void backtracking(int cnt, int extra_arrow, int score_l, int score_a) {
    if (cnt == SIZE + 1) { //0점 과녁까지 탐색
        int curr_diff = score_l - score_a;
        if (diff < curr_diff) {
            diff = curr_diff;
            answer = lion;
        } else if (diff == curr_diff && curr_diff != 0) {
            for (int i = SIZE; i >= 0; i--) {
                if (answer[i] > lion[i]) {
                    break;
                } else if (answer[i] < lion[i]) {
                    answer = lion;
                    break;
                }
            }
        }
        return;
    }
    for (int i = extra_arrow; i >= 0; i--) {
        lion[cnt] = i;
        if (apeach[cnt] < i) { //라이언 승
            backtracking(cnt + 1, extra_arrow - i, score_l + 10 - cnt, score_a);
        } else if (apeach[cnt] != 0) { //어피치 승
            backtracking(cnt + 1, extra_arrow - i, score_l, score_a + 10 - cnt);
        } else {
            backtracking(cnt + 1, extra_arrow, score_l, score_a);
        }
        lion[cnt] = 0;
        if (cnt == 10) { //마지막 과녁이었으면 남은 화살 다 써야하니까 더 탐색 안하고 바로 리턴
            return;
        }
    }
}

vector<int> solution(int n, vector<int> info) {
    apeach = info; //백트래킹 돌리기 위해 전역변수에 복사
    backtracking(0, n, 0, 0); //연산
    return answer;
}

/**
 * [양궁대회]
 *
 * 가능한 모든 경우를 백트래킹 탐색을 통해 검사
 * 가장 큰 점수 차이가 동일한 경우, 낮은 점수를 더 많이 맞힌 경우를 조건문으로 해결
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