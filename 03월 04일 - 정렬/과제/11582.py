import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
k = int(input())

# n / k 개의 배열을 각각 정렬합니다.
l = n//k    # 부분 배열의 길이
for i in range(k):
    sub_arr = sorted(arr[l*i : l*(i+1)])
    for j in sub_arr:
        print(j, end=' ')