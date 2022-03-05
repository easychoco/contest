import bisect,collections,copy,heapq,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())

mod = 1000000007

n = I()
a = LI()

if a[0] != 0:
  print(0)
  exit()

# dp[i] = i まで見たときのくみあわせ
dp = [0] * n

# hist[i] = これまでに i がでた回数
hist = [0] * n

dp[0] = 3
hist[0] = 1

for i in range(1, n):
  if a[i] == 0: dp[i] = dp[i - 1] * (3 - hist[a[i]]) % mod
  else: dp[i] = dp[i - 1] * (hist[a[i] - 1] - hist[a[i]]) % mod
  hist[a[i]] += 1

print(dp[-1])
