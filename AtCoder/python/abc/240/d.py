import bisect,collections,copy,heapq,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())

n = I()
a = LI()

st = []
ans = 0
for v in a:
  if len(st) == 0:
    st.append((v, 1))
  else:
    (val, cnt) = st[-1]
    if val != v:
      st.append((v, 1))
    else:
      if cnt + 1 == val:
        st.pop()
        ans -= val
      else: st[-1] = (val, cnt + 1)
  ans += 1
  print(ans)
