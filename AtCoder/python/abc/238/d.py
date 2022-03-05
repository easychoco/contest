import bisect,collections,copy,heapq,itertools,math,string
from re import A
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())

t = I()
for _ in range(t):
  a, s = LI()
  x = a
  y = s - x
  print('Yes' if y >= 0 and x & y == a else 'No')
