import bisect,collections,copy,heapq,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())

s = S()
q = I()
for _ in range(q):
  t, k = LI()
  odd = []
  k -= 1
  while k > 0 and t > 0:
    odd.append(k % 2 == 1)
    k //= 2
    t -= 1
  t += ord(s[k]) - ord('A')
  for v in odd:
    if v: t += 2
    else: t += 1

  t %= 3
  if t == 0: print('A')
  elif t == 1: print('B')
  elif t == 2: print('C')
