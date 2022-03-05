import bisect,collections,copy,heapq,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())

a, n = LI()
que = collections.deque()
limit = 1000000
score = [-1] * limit

que.append((1, 0))
while len(que) > 0:
  now, depth = que.popleft()
  if score[now] > 0: continue
  score[now] = depth
  if now == n: break
  if now * a < limit and score[now * a] == -1:
    que.append((now * a, depth + 1))

  if now < 10 or now % 10 == 0: continue

  now = str(now)
  nx = now[-1] + now[:-1]
  nx = int(nx)
  if nx < limit and score[nx] == -1:
    que.append((nx, depth + 1))

print(score[n])
