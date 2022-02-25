import sys
input = sys.stdin.readline

n = int(input())
arr1 = list(map(int, input().split()))
arr2 = list(map(int, input().split()))

arr1.sort()             # 오름차순
arr2.sort(reverse=True) # 내림차순

answer = 0
for i in range(n):
    answer += arr1[i]*arr2[i]

print(answer)