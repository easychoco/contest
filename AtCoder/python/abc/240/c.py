import bisect,collections,copy,heapq,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())


n, x = LI()
dp = [0] * 10010
dp[0] = 1
for _ in range(n):
  nx = [0] * 10010
  a, b = LI()
  for i in range(10001 - b):
    nx[i + a] += dp[i]
    nx[i + b] += dp[i]
  dp = nx

print('Yes' if dp[x] > 0 else 'No')
