import bisect,collections,copy,heapq,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())

n = I()
a = LI()

deg = [0, 360]

now = 0
for d in a:
  now += d
  now %= 360
  deg.append(now)

deg.sort()
ans = 0
for i in range(n + 1):
  ans = max(ans, deg[i + 1] - deg[i])

print(ans)
