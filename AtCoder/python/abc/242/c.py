import bisect,collections,copy,heapq,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())

n = I()
mod = 998244353

ans = [[0] * 10 for _ in range(n + 1)]
for i in range(10):
  ans[1][i] = 1 
for i in range(1, n):
  # to 9
  ans[i + 1][9] += ans[i][9]
  ans[i + 1][9] += ans[i][8]

  # to 1
  ans[i + 1][1] += ans[i][2]
  ans[i + 1][1] += ans[i][1]

  # to 2-8
  for j in range(2, 9):
    ans[i + 1][j] += ans[i][j - 1]
    ans[i + 1][j] += ans[i][j]
    ans[i + 1][j] += ans[i][j + 1]

  for j in range(1, 10):
    ans[i + 1][j] %= mod

sum = 0
for j in range(1, 10):
  sum += ans[n][j]

print(sum % mod)
