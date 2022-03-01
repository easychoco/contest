import bisect,collections,copy,heapq,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())

n = I()
graph = [[] for _ in range(n + 1)]

for i in range(1, n):
  p = I()
  graph[i].append(p)
  graph[p].append(i)

ans = [0] * n

sys.setrecursionlimit(10 ** 6)
def dfs(now, parent):
  tot = 1
  score = 0
  for to in graph[now]:
    if to == parent: continue
    v = dfs(to, now)
    tot += v
    score = max(score, v)
  score = max(score, n - tot)
  ans[now] = score
  return tot

dfs(0, -1)
for a in ans: print(a)

