import bisect,collections,copy,itertools,math,string
from heapq import  *
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())

n, k = LI()
p = LI()

que = []
for i in range(k):
  heappush(que, p[i])

print(que[0])
for i in range(k, n):
  if p[i] > que[0]:
    heappushpop(que, p[i])
  print(que[0])
