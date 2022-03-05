import bisect,collections,copy,heapq,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())

n = I()
xy = [(LI()) for _ in range(n)]

ans = 0
for i in range(n):
  for j in range(i):
    x1, y1 = xy[i]
    x2, y2 = xy[j]
    ans = max(ans, (x1 - x2)**2 + (y1 - y2)**2)
print(math.sqrt(ans))