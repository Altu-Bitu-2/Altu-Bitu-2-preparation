INF = 10**9 * 2

def floyd_warshall(n, graph):
    for k in range(1, n+1):
        for i in range(1, n+1):
            for j in range(1, n+1):
                if graph[i][k] + graph[k][j] < graph[i][j]:
                    graph[i][j] = graph[i][k] + graph[k][j]
    return graph

def solution(n, s, a, b, fares):
    answer = 0
    graph = [[INF]*(n+1) for _ in range(n+1)]
        
    for node1, node2, weight in fares:
        graph[node1][node2] = weight
        graph[node2][node1] = weight
        
    for i in range(1, n+1):
        graph[i][i] = 0
    graph = floyd_warshall(n, graph)
    
    answer = graph[s][a] + graph[s][b]
    for i in range(1, n+1):
        answer = min(answer, graph[s][i]+graph[i][a]+graph[i][b])
    
    return answer