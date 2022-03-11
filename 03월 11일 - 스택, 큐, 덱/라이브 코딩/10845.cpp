#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int SIZE = 1e4 + 1; //1부터 값이 들어가므로

vector<int> queue_vec(SIZE);
int front_pointer = 0, rear_pointer = 0;

//push: 삽입
void push(int x) {
    rear_pointer = (rear_pointer + 1) % SIZE;
    queue_vec[rear_pointer] = x;
}

//full: 큐가 꽉 찼는지 확인 (런타임 에러 방지용)
bool full() {
    return (rear_pointer + 1) % SIZE == front_pointer;
}

//pop: 가장 앞에 있는 값 삭제
void pop() {
    front_pointer = (front_pointer + 1) % SIZE;
}

//size: 큐 사이즈(원소 개수) 반환
int size() { //rear = 0, front = 1 ?
    int tmp = rear_pointer - front_pointer;
    if (tmp < 0) {
        tmp += SIZE;
    }
    return tmp;
}

//empty: 큐가 비어있는지 확인
bool empty() {
    return front_pointer == rear_pointer;
}

//front: 큐의 가장 앞 정수 출력
int front() {
    return queue_vec[(front_pointer + 1) % SIZE];
}

//back: 큐의 가장 뒤 정수 출력
int back() {
    return queue_vec[rear_pointer];
}

int main() {
    int n, x;
    string cmd;
    queue<int> q;

    //입력
    cin >> n;
    while (n--) {
        cin >> cmd;
        if (cmd == "push") {
            cin >> x;
            //if (!full()) { //라이브러리 사용 시 필요 x
            q.push(x);
            //}
            continue;
        }
        if (cmd == "pop") {
            if (q.empty()) { //큐가 비어있다면
                cout << "-1\n";
            } else {
                cout << q.front() << '\n';
                q.pop();
            }
            continue;
        }
        if (cmd == "size") {
            cout << q.size() << '\n';
            continue;
        }
        if (cmd == "empty") {
            cout << q.empty() << '\n';
            continue;
        }
        if (cmd == "front") {
            if (q.empty()) {
                cout << "-1\n";
            } else {
                cout << q.front() << '\n';
            }
            continue;
        }
        if (cmd == "back") {
            if (q.empty()) {
                cout << "-1\n";
            } else {
                cout << q.back() << '\n';
            }
            continue;
        }
    }

    //큐의 순회
//    while (!q.empty()) {
//        cout << q.front() << ' ';
//        q.pop();
//    }
    return 0;
}