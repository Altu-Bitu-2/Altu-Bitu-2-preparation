#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, input;
    set<int> s;

    //입력
    cin >> n;
    while (n--) {
        cin >> input;
        s.insert(input); //set에 삽입
    }
    //출력
    for (auto iter = s.begin(); iter != s.end(); iter++) { //set 순회
        cout << *iter << ' ';
    }
    return 0;
}