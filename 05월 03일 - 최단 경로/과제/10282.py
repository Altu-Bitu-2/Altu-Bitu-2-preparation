import sys
import heapq as hq
input = sys.stdin.readline

"""
[해킹]

"""

def dijkstra(n, c, graph):
    visited = [False] * (n+1)

    pq = [(0, c)]
    
    t = 0
    cnt = 0

    while pq:
        curr_t, curr = hq.heappop(pq)
        if visited[curr]:
            continue
        visited[curr] = True
        t = curr_t
        cnt += 1
        for next, weight in graph[curr]:
            if not visited[next]:
                hq.heappush(pq, (t + weight, next))
    
    return cnt, t



t = int(input())

for _ in range(t):
    n, d, c = map(int, input().split())
    graph = [[] for _ in range(n+1)]

    for _ in range(d):
        a, b, s = map(int, input().split())
        graph[b].append((a, s))
    print(*dijkstra(n, c, graph))