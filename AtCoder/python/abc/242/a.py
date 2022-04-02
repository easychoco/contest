import bisect,collections,copy,heapq,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())


a, b, c, x = LI()

if x <= a:
  print(1.0)
elif x <= b:
  print(c / (b - a))
else:
  print(0.0)

