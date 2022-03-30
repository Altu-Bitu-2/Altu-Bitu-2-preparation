#include <iostream>
#include <vector>

using namespace std;

// 필요한 동전 개수의 최솟값을 구하는 함수
int countCoin(int n, int value, vector<int> &coin){
    // coin이 이미 오름차순으로 주어졌으므로, 정렬할 필요는 없다
    int count = 0, idx = n-1;
    while (value) {
        count += value / coin[idx];
        value %= coin[idx--];
    }
    return count;
}

int main() {
    int n, k;
    // 입력
    cin >> n >> k;
    vector<int> coin(n);
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }
    // 연산 + 출력
    cout << countCoin(n, k, coin);
    return 0;
}