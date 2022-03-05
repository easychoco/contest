import bisect,collections,copy,heapq,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())

def create(a, d):
  ret = []
  seq = []
  if a == 0: return ret
  while a < 10 and a >= 0 and len(seq) <= 18:
    seq.append(a)
    ret.append(int("".join(map(str, seq))))
    a += d
  return ret

x = I()

st = set()
for d in range(-9, 10):
  for a in range(1, 10):
    st |= set(create(a, d))

seq = list(st)
seq.sort()
print(seq[bisect.bisect_left(seq, x)])
