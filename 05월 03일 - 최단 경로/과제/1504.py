import sys
import heapq as hq
input = sys.stdin.readline

INF = 2*10**8 + 1

def dijkstra(n, graph, start, end):
    dist = [INF]*(n+1)
    pq = [(0, start)]

    dist[start] = 0 

    while pq:
        weight, curr = hq.heappop(pq)
        if weight > dist[curr]:
            continue
        for next, next_weight in graph[curr]:
            new_weight = next_weight + weight
            if new_weight < dist[next]:
                dist[next] = new_weight
                hq.heappush(pq, (new_weight, next))

    return dist[end]


n, e = map(int, input().split())
graph = [[] for _ in range(n+1)]

for _ in range(e):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))
    graph[b].append((a, c))

v1, v2 = map(int, input().split())

ans = min(dijkstra(n, graph, 1, v1) + dijkstra(n, graph, v2, n), dijkstra(n, graph, 1, v2) + dijkstra(n, graph, v1, n)) + dijkstra(n, graph, v1, v2)

if ans >= INF:
    print(-1)
else:
    print(ans)