import bisect,collections,copy,heapq,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())

x1, y1, x2, y2 = LI()

pos = [
  (2, 1),
  (2, -1),
  (-2, 1),
  (-2, -1),
  (1, 2),
  (-1, 2),
  (1, -2),
  (-1, -2),
]

for (dx, dy) in pos:
  x = x1 + dx
  y = y1 + dy
  if (x - x2) ** 2 + (y - y2) ** 2 == 5:
    print('Yes')
    exit()

print('No')






