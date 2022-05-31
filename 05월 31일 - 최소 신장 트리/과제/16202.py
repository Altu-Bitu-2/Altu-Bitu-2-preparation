import sys
input = sys.stdin.readline

"""
[MST 게임]

최소 신장 트리를 만들 때, 간선의 가중치를 기준으로 정렬한다면 첫번째 간선은 무조건 사용하게 되어 있음
-> 첫번째에는 이미 유니온 된 정점이 하나도 없으므로
따라서, i번째 턴에서 제외하게 되는 간선은 i-1번째 간선일 것이다! (이때 i > 1)
간선을 배열에 저장해서 i번째 간선부터 크루스칼 알고리즘 사용

vertex[i] = (u, v) -> u부터 v로 향하는 가중치 i인 간선 존재
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

def kruskal(n, m, vertex, turn):
    cost = 0
    cnt = 0
    for w in range(turn, m+1):
        u, v = vertex[w]
        if not union(u, v):
            continue

        cost += w
        cnt += 1

        if cnt == n-1:
            return cost

    return 0

n, m, k = map(int, input().split())

vertex = [None] + [tuple(map(int, input().split())) for _ in range(m)]

result = []

for turn in range(1, k+1):
    # 초기화
    parent = [-1]*(n+1)
    # 연산
    result.append(kruskal(n, m, vertex, turn))

    if result[-1] == 0: # 이후의 턴은 모두 0점이므로
        break

result += [0]*(k-len(result))

# 출력
print(*result)