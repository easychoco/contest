import bisect,collections,copy,heapq,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())

x, y = LI()
n = I()
wv = [LI() for _ in range(n)]

sz = x + y

# dp[i][j] = 重さが i で j 個使ったときの 価値の最大値
dp = [[0] * (x + 1) for _ in range(sz + 1)]

for (i, (w, v)) in enumerate(wv):
  nx = [[0] * (x + 1) for _ in range(sz + 1)]
  for j in range(sz + 1):
    for k in range(1, x + 1):
      if j - w >= 0:
        nx[j][k] = max(dp[j][k], dp[j - w][k - 1] + v)
      else: nx[j][k] = dp[j][k]
  dp = nx

ans = 0
for v in dp:
  for score in v:
    ans = max(ans, score)

print(ans)
