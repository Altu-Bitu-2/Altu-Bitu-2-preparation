import sys
input = sys.stdin.readline

# 버블 정렬
def bubbleSort(n):
    cnt = 0
    for i in range(n):
        for j in range(1, n-i):
            if (arr[j-1] > arr[j]):
                arr[j], arr[j-1] = arr[j-1], arr[j]
            cnt += 1
    
    # print("Count :", cnt)

# 향상된 버블 정렬
def bubbleSortAdv(n):
    cnt = 0
    for i in range(n):
        flag = True
        for j in range(1, n-i):
            if (arr[j-1] > arr[j]):
                flag = False
                arr[j], arr[j-1] = arr[j-1], arr[j]
            cnt += 1
        if (flag):
            break
    
    # print("Count :", cnt)

n = int(input())
arr = [int(input()) for _ in range(n)]

#bubbleSort(n)
bubbleSortAdv(n)

for i in arr:
    print(i)