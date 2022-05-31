import sys
input = sys.stdin.readline

"""
[전력난]

모든 집에서 서로 왕복할 수 있는 상태를 유지하면서 가로등을 꺼야 하는 문제
문제에서 주어지는 간선을 오름차순으로 정렬한 후, 크루스칼 알고리즘을 통해 최소신장트리(MST) 구하기

!주의! 가로등을 설치하는데 드는 비용이 아니라, 가로등을 꺼서 절약할 수 있는 최대 비용을 구해야 함
"""

# find 연산
def find_parent(x):
    if parent[x] < 0:
        return x
    
    parent[x] = find_parent(parent[x])
    return parent[x]

# union 연산
def union(x, y):
    px = find_parent(x)
    py = find_parent(y)

    if px == py:
        return False
    
    if parent[px] < parent[py]:
        parent[px] += parent[py]
        parent[py] = px
    else:
        parent[py] += parent[px]
        parent[px] = py

    return True

def kruskal(n, vertex):
    cost = 0
    cnt = 0
    for u, v, w in vertex:
        if not union(u, v):
            continue

        cost += w
        cnt += 1

        if cnt == n-1:
            return cost

    return cost

while True:
    # 입력
    m, n = map(int, input().split())
    if m == n == 0:
        break
    vertex = [tuple(map(int, input().split())) for _ in range(n)]

    # 초기화
    parent = [-1]*(m)

    vertex.sort(key=lambda x:x[2])  # 정렬

    # 연산 & 출력
    print(sum(map(lambda x:x[2], vertex)) - kruskal(m, vertex))