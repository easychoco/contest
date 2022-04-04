import bisect,collections,copy,heapq,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())

s = LS()
t = LS()
cnt = sum([sv == tv for sv, tv in zip(s, t)])
print('No' if cnt == 1 else 'Yes')