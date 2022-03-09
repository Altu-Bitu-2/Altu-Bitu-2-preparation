#include <iostream>
#include <vector>
#include <stack>

using namespace std;
const int SIZE = 1e4; //스택 사이즈

vector<int> stack_vec(SIZE);
int top_pointer = -1; //스택의 현재 위치 가리키는 포인터

//push: 삽입
void push(int x) {
    stack_vec[++top_pointer] = x;
}

//full: 스택이 꽉 찼는지 확인 (직접 구현 시, 런타임 에러 방지용)
bool full() {
    return top_pointer == SIZE - 1;
}

//empty: 비어있는지 확인
bool empty() {
    return top_pointer == -1; //비었으면 true, 아니면 false 리턴
}

//pop: 가장 위 값 삭제
void pop() {
    top_pointer--;
}

//size
int size() {
    return top_pointer + 1; //(현재 가리키는 포인터 값 + 1)이 스택 사이즈
}

//top: 가장 위 값 반환 (삭제 x)
int top() {
    return stack_vec[top_pointer];
}

int main() {
    int n, x;
    string cmd; //명령
    stack<int> st;

    //입력
    cin >> n;
    while (n--) { //명령 입력받고 연산
        cin >> cmd;
        if (cmd == "push") {
            cin >> x;
            //라이브러리 사용 시 full() 필요 x
            //if (!full()) { //스택이 꽉 차지 않은 경우
            st.push(x);
            //}
            continue;
        }
        if (cmd == "pop") {
            if (st.empty()) { //스택이 비어있다면
                cout << "-1\n";
            } else {
                cout << st.top() << '\n';
                st.pop();
            }
            continue;
        }
        if (cmd == "size") {
            cout << st.size() << '\n';
            continue;
        }
        if (cmd == "empty") {
            cout << st.empty() << '\n';
            continue;
        }
        if (cmd == "top") {
            if (st.empty()) {
                cout << "-1\n";
            } else {
                cout << st.top() << '\n';
            }
            continue;
        }
    }

    //스택의 순회
//    while (!st.empty()) {
//        cout << st.top() << ' ';
//        st.pop();
//    }
    return 0;
}