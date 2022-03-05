import bisect,collections,copy,heapq,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())

n, m = LI()
graph = [[] for _ in range(n)]
# 入り次数
deg = [0] * n
for i in range(m):
  a, b = LI()
  a -= 1
  b -= 1
  graph[a].append(b)
  deg[b] += 1

sorted = []
que = []
for i in range(n):
  if deg[i] == 0: heapq.heappush(que, i)

while len(que) > 0:
  now = heapq.heappop(que)
  sorted.append(now + 1)
  for nx in graph[now]:
    deg[nx] -= 1
    if deg[nx] == 0: heapq.heappush(que, nx)

if len(sorted) < n: print(-1)
else:
  for v in sorted: print(v)
