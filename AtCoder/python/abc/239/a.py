import bisect,collections,copy,heapq,itertools,math,string
from decimal import Decimal
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())

h = I()
print(Decimal(h * (12800000 + h)) ** Decimal(0.5))
