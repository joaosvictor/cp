from collections import defaultdict
from math import inf
 
 
def dijkstra(g, vertex_size, start_vertex):
    from heapq import heappop, heappush
    from math import inf
 
    d = [inf] * vertex_size
    seen = [False] * vertex_size
    q = [(0, start_vertex)]  # (cost, node)
    d[start_vertex] = 0
    while q:
        v = heappop(q)[1]
        if seen[v]:
            continue
        seen[v] = True
        for cost, to in g[v]:
            if not seen[to] and d[v] + cost < d[to]:
                d[to] = d[v] + cost
                heappush(q, (d[to], to))
    return d
 
 
N, M = map(int, input().split())
 
g1 = defaultdict(list)
g2 = defaultdict(list)
for _ in range(M):
    A, B, C = map(int, input().split())
    A -= 1
    B -= 1
    g1[A].append((C, B))
    g2[B].append((C, A))
 
for i in range(N):
    ans = inf
 
    for c, j in g1[i]:
        if i == j and ans > c:
            ans = c
 
    d1 = dijkstra(g1, N, i)
    d2 = dijkstra(g2, N, i)
 
    for j in range(N):
        if i != j and ans > d1[j] + d2[j]:
            ans = d1[j] + d2[j]
 
    if ans == inf:
        ans = -1
    print(ans)
