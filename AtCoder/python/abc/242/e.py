import bisect,collections,copy,heapq,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())

mod = 998244353

def ord_minus(s):
  return ord(s) - ord('A') + 1

t = I()
for _ in range(t):
  n = I()
  s = list(map(ord_minus, S()))
  half = (n + 1) // 2
  rev = s[:(n // 2)]
  rev.reverse()
  # print(s, s[:half] + rev)
  ans = [0] * half
  ans[0] = s[0]
  for i in range(1, half):
    ans[i] += (ans[i - 1] - 1) * 26
    ans[i] += s[i]
    ans[i] %= mod
  if s < s[:half] + rev: ans[-1] += mod - 1
  # print(s[:half], rev)
  print(ans[-1] % mod)
