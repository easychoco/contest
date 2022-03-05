import bisect,collections,copy,heapq,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())

n = I()

oa = ord('a')
ans = [('a', 1)]
for i in range(1, n):
  nx = []
  for (s, m) in ans:
    for v in range(m):
      nx.append((s + chr(oa + v), m))
    nx.append((s + chr(oa + m), m + 1))
  ans = nx

for (s, m) in ans:
  print(s)