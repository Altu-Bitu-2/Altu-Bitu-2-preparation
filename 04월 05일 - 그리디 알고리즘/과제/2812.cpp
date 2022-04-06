#include <iostream>
#include <string>
#include <deque>

using namespace std;

//k개의 수 지워서 큰 수 만드는 함수
string findMaxNumber(string number, int l, int k) {
    deque<int> dq;

    int cnt = 0;
    for (int i = 0; i < l; i++) {
        while (cnt < k && !dq.empty() && dq.front() < number[i] - '0') {
            dq.pop_front();
            cnt++;
        }
        dq.push_front(number[i] - '0'); //이번 입력 삽입
    }
    while (dq.size() > (l - k)) { //충분히 지우지 못했다면 앞에서부터(자릿수가 작은 숫자) 지우기
        dq.pop_front();
    }

    string answer = "";
    while (!dq.empty()) { //큰 자릿수부터 정답에 추가
        answer += (dq.back() + '0');
        dq.pop_back();
    }
    return answer;
}

/**
 * [크게 만들기]
 *
 * 어차피 남는 수는 n-k자리 수!
 * 가능한 앞자리에 큰 수를 배치하는 것이 유리하다.
 * 수의 앞자리부터 탐색하며, 덱에 차례대로 저장
 * 직전 자리보다 큰 수가 나오면 덱의 front가 자신보다 크거나 같아질 때까지 pop_front한 뒤에 추가
 *
 * ex) 1924 에서 2개를 지워서 큰 수를 만들어야 한다면
 *    stack: []           이번 숫자 '1' -> stack: ['1']
 *    stack: ['1']        이번 숫자 '9' -> stack: ['9']
 *    stack: ['9']        이번 숫자 '2' -> stack: ['9', '2']
 *    stack: ['9', '2']   이번 숫자 '4' -> stack: ['9', '4']
 *
 *    답: 94
 *
 * 이러한 그리디적 풀이가 가능한 이유 -> number의 순서가 고정되어 있기 때문!
 *
 * !주의! 커지는 값이 나와도, 이미 k번 수를 지웠다면 더 이상 지우면 안됨
 * !주의! 마지막까지 검사했는데 k번 지우지 못했다면 마지막 값들을 지워서 k번을 채움
 */

int main(){
    int n, k;
    string number;

    //입력
    cin >> n >> k >> number;

    //연산 & 출력
    cout << findMaxNumber(number, number.length(), k);
    return 0;
}