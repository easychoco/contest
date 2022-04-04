import bisect,collections,copy,heapq,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())

n = I()
t = S()

dx = [1, 0, -1, 0]
dy = [0, -1, 0, 1]

nx, ny = 0, 0
di = 0
for c in t:
  if c == 'R': di = (di + 1) % 4
  if c == 'S':
    nx += dx[di]
    ny += dy[di]

print(nx, ny)