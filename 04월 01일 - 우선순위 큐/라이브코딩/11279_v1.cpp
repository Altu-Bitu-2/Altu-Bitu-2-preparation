#include <iostream>
#include <vector>

using namespace std;

bool empty(vector<int> &heap) {
    return heap.size() == 1;
}

void push(vector<int> &heap, int value) {
    // 0. 현재 heap의 크기 = 새로 push할 데이터의 초기 인덱스
    int idx = heap.size();
    // 1. 우선 힙의 마지막 자리에 value 삽입
    heap.push_back(value);

    // 부모노드와 비교하면서 바꿀 수 있을 때까지 바꾼다.
    while (idx > 1 && heap[idx] > heap[idx / 2]) {
        swap(heap[idx], heap[idx / 2]);   // 부모노드와 swap
        idx /= 2;   // 현재 value가 위치한 인덱스
    }
    return;
}

int pop(vector<int> &heap) {
    // 우선, 빈 루트노트에 가장 뒤에 있는 값을 옮겨준다.
    int item = heap[1]; // 제거하는 값을 반환하기 위해 복사
    swap(heap[1], heap[heap.size() - 1]);
    heap.pop_back();    // 데이터 제거

    int size = heap.size(); // 힙의 크기
    int parent = 1, child = 2;
    // 자식노드가 존재하는 동안 비교 진행
    while (child < size) {
        // 오른쪽 자식노드가 존재한다면, 둘 중 큰 쪽을 선택함
        if (child + 1 < size && heap[child] < heap[child + 1]) {
            child += 1;
        }

        // 부모노드의 값이 작다면 swap
        if (heap[parent] < heap[child]) {
            swap(heap[parent], heap[child]);
            parent = child;
            child = parent * 2;
        } else {    // 자식보다 부모노드가 큰 상황이므로 더 이상 swap은 필요 없음
            break;
        }
    }
    return item;
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    cin >> n;

    // heap 초기화
    vector<int> heap_vec;
    heap_vec.push_back(0);

    while (n--) {
        cin >> x;
        if (x == 0) {
            if (empty(heap_vec)) {
                cout << "0\n";
            } else {
                cout << pop(heap_vec) << '\n';  // 출력 & 삭제
            }
        } else {
            push(heap_vec, x);  // 삽입
        }
    }
    return 0;
}