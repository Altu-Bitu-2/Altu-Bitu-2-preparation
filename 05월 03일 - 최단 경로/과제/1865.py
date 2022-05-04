import sys
input = sys.stdin.readline

def bellman_ford(n, edges):
    dist = [0] * (n+1)

    for i in range(n+1):
        flag = False

        for s, e, t in edges:
            if dist[s] + t < dist[e]:
                dist[e] = dist[s] + t
                flag = True

        if not flag:
            return "NO"

        if i == n:
            return "YES"

tc = int(input())
for _ in range(tc):

    # 입력
    n, m, w = map(int, input().split())

    edges = []

    for _ in range(m):
        s, e, t = map(int, input().split())
        edges.append((s, e, t))
        edges.append((e, s, t))

    for _ in range(w):
        s, e, t = map(int, input().split())
        edges.append((s, e, -t))
    
    
    print(bellman_ford(n, edges))