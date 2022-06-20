import sys
from collections import deque
input = sys.stdin.readline

"""
[장난감 부품]

- 완제품을 만들기 위해 필요한 기본 부품의 개수를 구하는 문제
-> 위상 정렬을 역으로 수행하여 리프노드의 필요한 개수를 기록
"""

def reverse_topological(n, graph):
    que = deque()
    cnt = [0] * (n + 1)
    ans = [0] * (n + 1)

    que.append(n)
    cnt[n] = 1  # 큐에 있는 부품 번호에 따른 개수 저장

    while que:
        x = que.popleft()

        # 리프노드(기본부품)인 경우
        if not graph[x]:
            ans[x] += cnt[x]
        # 중간부품인 경우
        for y, k in graph[x]:
            # 큐에 없으면 삽입
            if not cnt[y]:
                que.append(y)
            cnt[y] += k * cnt[x]

        cnt[x] = 0  # 처리가 끝나면 0으로 리셋
    return ans

# 입력
n = int(input())
m = int(input())

graph = [list() for _ in range(n+1)]
for _ in range(m):
    x, y, k = map(int, input().split())
    graph[x].append((y, k))

# 연산
ans = reverse_topological(n, graph)

# 출력
for i in range(1, n+1):
    if ans[i]:
        print(i, ans[i])