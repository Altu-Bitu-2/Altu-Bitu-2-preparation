import sys

input = sys.stdin.readline

n = int(input())


# arr = [list((lambda x: (x[0], int(x[1]), int(x[2]), int(x[3])))(input().split())) for _ in range(n)]

# lambda 함수 사용법....
# arr = [list((lambda x: (x[0], list(map(int, x[1:]))))(input().split())) for _ in range(n)]
# arr.sort(key=lambda x: (-x[1][0], x[1][1], -x[1][2], x[0]))

initializeInput = lambda x:(-int(x[1]), int(x[2]), -int(x[3]), x[0])
arr = [list(initializeInput(input().split())) for _ in range(n)]
arr.sort()

for i in arr:
    print(i[-1])