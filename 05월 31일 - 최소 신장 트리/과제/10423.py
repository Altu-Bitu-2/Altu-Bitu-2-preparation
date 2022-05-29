import sys
input = sys.stdin.readline

"""
[전기가 부족해]

모든 도시에 전기가 공급될 수 있도록 최소 비용으로 도시를 연결하는 문제
이 문제는 k개의 최소신장트리를 만들어야 하지만, 발전기가 있는 도시를 모두 가상의 정점에 연결한다고 생각하면 하나의 큰 트리를 이룸

-> 한번의 크루스칼 알고리즘으로 해결 가능
"""

def find_parent(x):
    if parent[x] < 0:
        return x
    
    parent[x] = find_parent(parent[x])
    return parent[x]

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
        if find_parent(u) == find_parent(v):
            continue
        union(u, v)
        cost += w
        cnt += 1

        if cnt == n-1:
            return cost

    return cost

# 입력
n, m, k = map(int, input().split())
power_plant = list(map(int, input().split()))

# 초기화
parent = [-1]*(n+1)

# 가상의 정점(0)에 연결
parent[0] = -k
for city in power_plant:
    parent[city] = 0

# 입력
vertex = [tuple(map(int, input().split())) for _ in range(m)]
vertex.sort(key=lambda x:x[2])  # 정렬

# 연산 & 출력
print(kruskal(n, vertex))