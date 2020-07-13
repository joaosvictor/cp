import sys
import numpy as np
 
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
 
MOD = 10**9 + 7
 
N, *P = map(int, read().split())
 
class UnionFind:
    def __init__(self, N):
        self.root = list(range(N))
        self.size = [1] * (N)
        self.has_loop = [False] * N
 
    def __getitem__(self, x):
        root = self.root
        while root[x] != x:
            root[x] = root[root[x]]
            x = root[x]
        return x
 
    def merge(self, x, y):
        x = self[x]
        y = self[y]
        if x == y:
            self.has_loop[x] = True
            return False
        sx, sy = self.size[x], self.size[y]
        if sx < sy:
            x, y = y, x
            sx, sy = sy, sx
        self.root[y] = x
        self.size[x] += sy
        self.has_loop[x] |= self.has_loop[y]
        return True
 
uf = UnionFind(N + 1)
for i, x in enumerate(P, 1):
    if x == -1:
        continue
    uf.merge(i, x)
 
loop = 0
sizes = []
for v in range(1, N + 1):
    if v != uf[v]:
        continue
    if uf.has_loop[v]:
        loop += 1
    else:
        sizes.append(uf.size[v])
 
S = len(sizes)
 
f = np.zeros(S + 10, np.int64)
f[0] = 1
for x in sizes:
    f[1:] += x * f[:-1]
    f %= MOD
f[1] -= S
 
fact = np.empty(N + 1, np.int64)
fact[0] = 1
for n in range(1, N + 1):
    fact[n] = n * fact[n - 1] % MOD
power = np.empty(N + 1, np.int64)
power[0] = 1
for n in range(1, N + 1):
    power[n] = (N - 1) * power[n - 1] % MOD
 
coef = fact[:S] * power[:S][::-1] % MOD
 
x = (f[1:S+1] * coef % MOD).sum() % MOD
x += loop * pow(N-1, S, MOD) % MOD
 
x = N * pow(N-1, S, MOD) - x
x %= MOD
print(x)
