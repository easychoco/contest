import bisect,collections,copy,heapq,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())


n = I()
st = set([i + 1 for i in range(2 * n + 1)])
for i in range(n):
  print(st.pop(), flush = True)
  m = I()
  st.remove(m)
print(st.pop())
