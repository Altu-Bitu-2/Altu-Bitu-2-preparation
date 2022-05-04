import sys
input = sys.stdin.readline

def floyd_warshall(n, graph, table):
    for k in range(1, n+1):
        for i in range(1, n+1):
            for j in range(1, n+1):
                if graph[i][k] + graph[k][j] < graph[i][j]:
                    graph[i][j] = graph[i][k] + graph[k][j]
                    table[i][j] = table[i][k]
    return

INF = 10**5 * 2
n, m = map(int, input().split())
graph = [[INF]*(n+1) for _ in range(n+1)]
table = [[0]*(n+1) for _ in range(n+1)]

for _ in range(m):
    a, b, s = map(int, input().split())
    graph[a][b] = graph[b][a] = s

    table[a][b] = b
    table[b][a] = a

floyd_warshall(n, graph, table)

for i in range(1, n+1):
    table[i][i] = '-'

for line in table[1:]:
    print(*line[1:])