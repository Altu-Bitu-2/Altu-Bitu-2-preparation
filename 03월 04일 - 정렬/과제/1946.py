import sys
input = sys.stdin.readline

def solve(n, arr):
    arr.sort()
    count = 0
    best_rank = n   # 현재까지 면접 순위 중 가장 높은 순위를 기록한다.
    for rank in arr:
        # 현재 최고의 면접 순위보다 우수해야 선발할 수 있다.
        if rank[1] < best_rank:
            count += 1
            best_rank = rank[1]

    return count


T = int(input())
for _ in range(T):
    n = int(input())
    arr = [list(map(int, input().split())) for _ in range(n)]
    print(solve(n, arr))