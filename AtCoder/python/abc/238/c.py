import bisect,collections,copy,heapq,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())

MOD = 998244353

def sum(a, l):
  return (l - a + 1) * (a + l) // 2

n = I()

ans = 0
base = 1
while base * 10 <= n:
  ans += sum(1, base * 9)
  ans %= MOD
  base *= 10

ans += sum(1, n - base + 1)
ans %= MOD
print(ans)
