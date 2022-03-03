#include <iostream>
#include <vector>

using namespace std;

vector<int> arr, sorted; //정렬해야하는 배열, 중간중간 정렬한 배열

//left ~ right 사이의 원소 상태 출력
void printArr(int left, int right, string tag) {
    cout << tag << " array: ";
    for (int i = left; i <= right; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

//합병 정렬(conquer & merge)
void merge(int left, int mid, int right) {
    //왼쪽 배열 시작(p1), 오른쪽 배열 시작(p2), 정렬한 배열 위치값(index)
    int p1 = left, p2 = mid + 1, index = left;

    while (p1 <= mid && p2 <= right) { //왼쪽 오른쪽 배열 모두 검사
        if (arr[p1] < arr[p2]) { //왼쪽 배열의 현재 값이 오른쪽 배열의 값보다 작다면
            sorted[index++] = arr[p1++]; //왼쪽 배열의 값 정렬하고, 인덱스 증가
        } else { //왼쪽 배열의 현재 값보다 오른쪽 배열의 값이 작거나 같다면
            sorted[index++] = arr[p2++]; //오른쪽 배열의 값 정렬하고, 인덱스 증가
        }
    }
    while (p1 <= mid) { //왼쪽 배열에 탐색하지 않은 원소가 있다면
        sorted[index++] = arr[p1++]; //정렬
    }
    while (p2 <= right) { //오른쪽 배열에 탐색하지 않은 원소가 있다면
        sorted[index++] = arr[p2++]; //정렬
    }
    //원래 배열에 다시 복사 -> 이래야 다음 conquer & merge 과정에서 올바른 검사 가능
    //(python3) 복사과정에서 반복문을 사용해도 되지만, 슬라이싱으로 한번에 복사 가능!
    for (int i = left; i <= right; i++) {
        arr[i] = sorted[i];
    }
}

//합병 정렬(divide)
void mergeSort(int n, int left, int right) {
    if (left < right) { //원소 하나가 될 때까지 나눔
        int mid = (left + right) / 2; //정확히 반으로 나눈다
        mergeSort(n, left, mid); //왼쪽 배열
        mergeSort(n, mid + 1, right); //오른쪽 배열

        //정렬 전 배열 출력
        printArr(left, mid, "left");
        printArr(mid + 1, right, "right");

        //정렬해서 합치기
        merge(left, mid, right);

        //정렬 후 배열 출력
        printArr(left, right, "Merged");
        cout << "=================\n";
    }
}

int main() {
    int n;

    //입력
    cin >> n;
    arr.assign(n, 0);
    sorted.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    //연산
    mergeSort(n, 0, n - 1);
    //출력
    for (int i = 0; i < n; i++) {
        cout << arr[i] << '\n';
    }
    return 0;
}