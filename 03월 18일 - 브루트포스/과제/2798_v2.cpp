#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX_SIZE = 3e5;

//재귀함수 사용시 함수를 계속 호출하므로 전역변수로 관리하는 것이 더 효율적
int n, m;
vector<int> card;
int diff = MAX_SIZE, ans;

//재귀함수 풀이
//카드를 중복으로 고르는 걸 방지하기 위해 t 매개변수를 활용해서 그 전에 고른 카드 번호 이후부터 고르도록
void selectCard(int cnt, int t, int sum) { //cnt: 카드 개수, t: 현재 카드 번호, sum: 카드 합
    if (cnt == 3) { //3장의 카드를 골랐다면
        if (diff > n - sum) {
            diff = n - sum;
            ans = sum;
        }
        return;
    }
    for (int i = t; i < n; i++) {
        if (sum + card[i] > m) { //더했을 때 합이 m을 넘는다면
            continue;
        }
        selectCard(cnt + 1, i + 1, sum + card[i]);
    }
}

int main() {
    //입력
    cin >> n >> m;
    card.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> card[i];
    }

    //연산
    sort(card.begin(), card.end());
    selectCard(0, 0, 0);

    //출력
    cout << ans << '\n';
    return 0;
}