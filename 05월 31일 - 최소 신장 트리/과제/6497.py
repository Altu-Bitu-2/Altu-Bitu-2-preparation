import sys
input = sys.stdin.readline

"""
[전력난]

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

# 입력
n, m = map(int, input().split())
position = [tuple(map(int, input().split())) for _ in range(n)]
vertex = []

for i in range(n):
    for j in range(i):
        dx = position[i][0] - position[j][0]
        dy = position[i][1] - position[j][1]

        vertex.append((i, j, (dx**2 + dy**2)**(1/2)))

# 초기화
parent = [-1]*(n)

for _ in range(m):
    u, v = map(int, input().split())
    union(u-1, v-1)

vertex.sort(key=lambda x:x[2])  # 정렬

# 연산 & 출력
print("%.2f" %(kruskal(n, vertex)))