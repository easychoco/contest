import bisect,collections,copy,heapq,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())

h, w, n = LI()
sx, sy = LI()
gx, gy = LI()

graph = [[] for _ in range(n)]

mpx = collections.defaultdict(list)
mpy = collections.defaultdict(list)

for _ in range(n):
  x, y = LI()
  mpx[x].append(y)
  mpy[y].append(x)

for li in mpx.values():
  li.sort()
for li in mpy.values():
  li.sort()

inf = 1001001001001
dist = collections.defaultdict(lambda: inf)
dist[(sx, sy)] = 0

que = collections.deque()
que.append((sx, sy))
while len(que) > 0:
  x, y = que.popleft()

  py = mpx[x]
  # 縦 / x 指定して y で探索
  y_idx = bisect.bisect_left(py, y) # lower_bound
  if y_idx - 1 >= 0:
    ny = py[y_idx - 1] + 1
    if dist[(x, y)] + 1 < dist[(x, ny)]:
      dist[(x, ny)] = dist[(x, y)] + 1
      que.append((x, ny))
  y_idx = bisect.bisect_right(py, y) # upper_bound
  if y_idx < len(py):
    ny = py[y_idx] - 1
    if dist[(x, y)] + 1 < dist[(x, ny)]:
      dist[(x, ny)] = dist[(x, y)] + 1
      que.append((x, ny))

  # 横 / y で指定して x で探索
  px = mpy[y]
  x_idx = bisect.bisect_left(px, x) # lower_bound
  if x_idx - 1 >= 0:
    nx = px[x_idx - 1] + 1
    if dist[(x, y)] + 1 < dist[(nx, y)]:
      dist[(nx, y)] = dist[(x, y)] + 1
      que.append((nx, y))
  y_idx = bisect.bisect_right(py, y) # upper_bound
  if x_idx < len(px):
    nx = px[x_idx] - 1
    if dist[(x, y)] + 1 < dist[(nx, y)]:
      dist[(nx, y)] = dist[(x, y)] + 1
      que.append((nx, y))

if dist[(gx, gy)] >= inf:
  dist[(gx, gy)] = -1

print(dist[(gx, gy)])
