#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;

int calc(string s) {
    int ans = 0;
    stack<char> st;
    map<char, int> num; //괄호 값
    map<char, char> bracket; //괄호 쌍

    bracket[')'] = '(';
    bracket[']'] = '[';
    num['('] = 2;
    num['['] = 3;

    int temp = 1;
    for (int i = 0; i < s.length(); i++) {
        switch (s[i]) {
            case '(':
            case '[':
                st.push(s[i]);
                temp *= num[s[i]]; //여는 괄호 시 곱하기
                break;
            case ')':
            case ']':
                if (st.empty() || st.top() != bracket[s[i]]) { //올바르지 않은 괄호
                    return 0;
                }
                if (s[i - 1] == bracket[s[i]]) {
                    ans += temp;
                }
                temp /= num[bracket[s[i]]];
                st.pop();
                break;
        }
    }
    if (st.empty()) {
        return ans;
    }
    return 0;
}

int main() {
    string s;

    //입력
    cin >> s;
    //연산 & 출력
    cout << calc(s);
    return 0;
} 