import bisect,collections,copy,heapq,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())

n, m, k, s, t, x = LI()
s -= 1
t -= 1
x -= 1
edge = []
for _ in range(m):
  u, v = LI()
  u -= 1
  v -= 1
  edge.append((u, v))

dp = [[0, 0] for _ in range(n)]
dp[s][0] = 1
for _ in range(k):
  nx = [[0, 0] for _ in range(n)]
  for (u, v) in edge:
    if u == x:
      # v -> u
      nx[u][0] += dp[v][1]
      nx[u][1] += dp[v][0]
      # u -> v
      nx[v][0] += dp[u][0]
      nx[v][1] += dp[u][1]
    elif v == x:
      # v -> u
      nx[u][0] += dp[v][0]
      nx[u][1] += dp[v][1]
      # u -> v
      nx[v][0] += dp[u][1]
      nx[v][1] += dp[u][0]
    else:
      # v -> u
      nx[u][0] += dp[v][0]
      nx[u][1] += dp[v][1]
      # u -> v
      nx[v][0] += dp[u][0]
      nx[v][1] += dp[u][1]
    nx[u][0] %= 998244353
    nx[u][1] %= 998244353
    nx[v][0] %= 998244353
    nx[v][1] %= 998244353
  dp = nx
print(dp[t][0])
