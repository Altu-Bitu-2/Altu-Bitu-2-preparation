#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> findNumber(string s) {
    vector<int> num(s.length(), 0);
    bool isTen = false; //0이 존재하는지 확인
    int sum = 0; //3의 배수인지 확인하기 위해 수 더함

    //돌면서 3의 배수와 10의 배수인지 확인
    for (int i = 0; i < s.length(); i++) {
        num[i] = s[i] - '0';
        sum += num[i];
        if (num[i] == 0) {
            isTen = true;
        }
    }

    if (sum % 3 != 0 || !isTen) { //3의 배수가 아니거나, 10의 배수가 아니라면
        return {-1};
    }
    return num;
}

/**
 * [30]
 * 30의 배수 = 10의 배수 && 3의 배수
 * 1. 10의 배수 -> 입력된 수에 0이 포함되어 있는지 확인
 * 2. 3의 배수 -> 모든 자리수의 합이 3의 배수인지 확인
 *
 * 30의 배수임이 확인 되었으면,
 * 가장 큰 수를 만들기 위해 9부터 0까지 역순으로 나열한다.
 */

int main() {
    string s;

    //입력
    cin >> s;

    //연산
    vector<int> num = findNumber(s);
    //출력
    if (num[0] == -1) {
        cout << "-1\n";
    } else {
        //가장 큰 수 만들기 위해 내림차순 정렬
        sort(num.begin(), num.end(), greater<>());

        for (int i = 0; i < num.size(); i++) {
            cout << num[i];
        }
    }
    return 0;
}