import bisect,collections,copy,heapq,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())


n, q = LI()
x = LI()
graph = [[] * n for _ in range(n)]
for _ in range(n - 1):
  a, b = LI()
  a -= 1
  b -= 1
  graph[a].append(b)
  graph[b].append(a)

ans = [[] for _ in range(n)]

# 再帰の制限をつける
sys.setrecursionlimit(10 ** 6)

def dfs(now, parent):
  if len(ans[now]) > 0: return ans[now]
  children = [x[now]]
  for nx in graph[now]:
    if nx == parent: continue
    children.extend(dfs(nx, now))
  
  list.sort(children, reverse=True)
  
  ans[now] = children[:20]
  return ans[now]

dfs(0, -1)

for _ in range(q):
  v, k = LI()
  print(ans[v - 1][k - 1])