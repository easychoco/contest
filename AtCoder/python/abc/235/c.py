import bisect,collections,copy,heapq,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())


n, q = LI()
a = LI()
mp = collections.defaultdict(list)
for i in range(n):
  mp[a[i]].append(i + 1)
for _ in range(q):
  x, k = LI()
  if len(mp[x]) >= k:
    print(mp[x][k - 1])
  else :print(-1)
