#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> skill;

// 조합 구하기
// (튜터용) - next_permutaion, prev_permutation 순서대로 출력하면서 보여줄 예정입니다.
void combination() {
    int arr[] = {1, 2, 3, 4};
    bool temp[] = {1, 1, 0, 0};

    do {
        for (int i = 0; i < 4; i++) {
//            cout << temp[i] << ' ';
            if (temp[i]) {
                cout << arr[i] << ' ';
            }
        }
        cout << '\n';
    } while (prev_permutation(temp, temp + 4));

}

// teamA에 속하는지를 저장한 벡터를 받아 능력치의 차이를 구하는 함수
int calcDiff(int n, vector<bool> &is_teamA) {
    vector<int> teamA;  // A에 속한 인덱스를 저장
    vector<int> teamB;  // B에 속한 인덱스를 저장

    int sumA, sumB;     // A, B의 각 능력치 합

    for (int i = 0; i < n; i++) {
        if (is_teamA[i]) {
            for (auto j: teamA) {
                // 기존에 있던 팀원과 함께할 때 능력치를 더해줌
                sumA += skill[i][j] + skill[j][i];
            }
            teamA.push_back(i); // 팀에 추가
        } else {
            for (auto j: teamB) {
                sumB += skill[i][j] + skill[j][i];
            }
            teamB.push_back(i); // 팀에 추가
        }
    }
    return abs(sumA - sumB);    // 절댓값 리턴
}

int make_team(int n) {
    // 조합을 구하기 위해 임시 배열 만들기
    // is_teamA[i] : i가 teamA에 속하는지 여부를 저장
    vector<bool> is_teamA(n, true);
    for (int i = 0; i < n / 2; i++) {
        // 앞부분을 false로 채워야 next_permutation으로 구할 수 있다.
        is_teamA[i] = false;
    }

    int answer = 1000;      // 100 (개인 능력치 최대) * 10 (n/2의 최댓값) = 1000

    do {
        // 각 팀의 능력치 차이의 최솟값을 갱신
        answer = min(answer, calcDiff(n, is_teamA));
    } while ((next_permutation(is_teamA.begin() + 1, is_teamA.end()))); // 두번씩 계산되는걸 방지하기 위해, 0번은 false로 고정
    return answer;
}

int main() {
    int n;
    // 입력
    cin >> n;
    skill.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> skill[i][j];
        }
    }
    cout << make_team(n);
    return 0;
}