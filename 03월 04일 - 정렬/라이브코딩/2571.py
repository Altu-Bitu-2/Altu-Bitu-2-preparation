import sys

# python의 기본 재귀 깊이는 1000으로, 매우 작은 편입니다.
# 따라서 재귀 함수를 이용한 풀이를 할 경우에 재귀 깊이를 설정해주는 코드를 넣어주어야 합니다.
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n = int(input())
arr = [int(input()) for _ in range(n)]
sorted_arr = [0]*n

def merge(left, mid, right):
    p1 = left
    p2 = mid + 1
    p3 = left

    while (p1 <= mid and p2 <= right):
        if (arr[p1] <= arr[p2]):
            sorted_arr[p3] = arr[p1]
            p1 += 1
            
        else:
            sorted_arr[p3] = arr[p2]
            p2 += 1

        p3 += 1
    
    # 왼쪽 배열이 남은 경우
    if p1 <= mid:
        sorted_arr[p3:right+1] = arr[p1:mid+1]
    # 오른쪽 배열이 남은 경우
    if p2 <= right:
        sorted_arr[p3:right+1] = arr[p2:right+1]
    
    # 원래 배열로 다시 복사
    arr[left:right+1] = sorted_arr[left:right+1]

def mergeSort(left, right):
    if (left < right):
        mid = (left+right)//2
        mergeSort(left, mid)
        mergeSort(mid+1, right)
        merge(left, mid, right)


# mergeSort(0, n-1)
arr.sort()  # 내장함수를 이용하세요.

for i in arr:
    print(i)