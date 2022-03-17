import bisect,collections,copy,heapq,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())

mod = 1000000007

n, k = LI()
graph = [[] for _ in range(n)]
for _ in range(n - 1):
  a, b = LI()
  a -= 1
  b -= 1
  graph[a].append(b)
  graph[b].append(a)

graph.append([])

# 再帰の制限をつける
sys.setrecursionlimit(2 * 10 ** 5)

def dfs(now, parent, res):
  ret = res
  used = 1
  if parent >= 0: used += 1
  for nx in graph[now]:
    if nx == parent: continue
    ret *= dfs(nx, now, k - used)
    if ret >= mod: ret %= mod
    used += 1
  return ret % mod

print(dfs(0, -1, k))
