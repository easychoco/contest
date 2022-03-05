import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))

n = I()
graph = [[] for _ in range(n)]

uv = [LI() for _ in range(n - 1)]

for u, v in uv:
  u -= 1
  v -= 1
  graph[u].append(v)
  graph[v].append(u)

ans_l = [10 ** 9] * n
ans_r = [-1] * n
leaf_num = 1

sys.setrecursionlimit(3 * 10 ** 5)

def dfs(now, parent):
  global leaf_num
  for child in graph[now]:
    if child == parent: continue
    if ans_r[child] < 0: dfs(child, now)
    ans_l[now] = min(ans_l[now], ans_l[child])
    ans_r[now] = max(ans_r[now], ans_r[child])
  if ans_r[now] < 0:
    ans_l[now] = leaf_num
    ans_r[now] = leaf_num
    leaf_num += 1

dfs(0, -1)

for (l, r) in zip(ans_l, ans_r):
  print(l, r)
