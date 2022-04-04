import bisect,collections,copy,heapq,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())

n, m = LI()
graph = [[] for _ in range(n)]
for _ in range(m):
  u, v = LI()
  u -= 1
  v -= 1
  graph[u].append(v)
  graph[v].append(u)

inf = 1001001001

deq = collections.deque()

# ans[i][j] = mask が i で、 最後尾が j のときの最短パス長
ans = [[inf] * n for _ in range(1 << n)]
ans[0][0] = 0
for i in range(n):
  ans[1 << i][i] = 1
  deq.append((1 << i, i))

while len(deq) > 0:
  now, back = deq.popleft()
  for to in graph[back]:
    next = now ^ (1 << to)
    if ans[now][back] + 1 < ans[next][to]:
      ans[next][to] = ans[now][back] + 1
      deq.append((next, to))

sum = 0
for i in range(1 << n):
  val = inf
  for j in range(n):
    val = min(val, ans[i][j])
  sum += val
print(sum)
