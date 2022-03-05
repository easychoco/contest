import bisect,collections,copy,heapq,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())

n = I()
x, y = 1, 1
for i in range(n):
  t, a = LI()
  mul = max((x - 1) // t, (y - 1) // a) + 1
  x = t * mul
  y = a * mul

print(x + y)
