#include <iostream>
#include <map>

using namespace std;

int main() {
    //입출력 속도 향상
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    string input;
    map<string, int> pocket_name; //이름이 key 번호가 value
    map<int, string> pocket_num; //번호가 key 이름이 value

    //입력 & 연산
    cin >> n >> m;
    for (int i = 1; i <= n; i++) { //번호 1번부터 시작하므로 1 ~ n까지
        cin >> input; //이름 입력 받기
        pocket_name[input] = i;
        pocket_num[i] = input;
    }
    while (m--) {
        cin >> input;
        if (isdigit(input[0])) { //숫자 입력이라면
            int number = stoi(input); //stoi: string to int
            cout << pocket_num[number] << '\n'; //number에 대응하는 value(이름) 출력
        } else { //문자열이라면
            cout << pocket_name[input] << '\n'; //이름에 대응하는 value(번호) 출력
        }
    }
    return 0;
}