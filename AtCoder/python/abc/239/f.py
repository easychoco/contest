import bisect,collections,copy,heapq,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())

# https://note.nkmk.me/python-union-find/
class UnionFind():
  def __init__(self, n):
    self.n = n
    self.parents = [-1] * n
  def root(self, x):
    if self.parents[x] < 0: return x
    else:
      self.parents[x] = self.root(self.parents[x])
      return self.parents[x]
  def unite(self, x, y):
    x = self.root(x)
    y = self.root(y)
    if x == y: return
    if self.parents[x] > self.parents[y]: x, y = y, x
    self.parents[x] += self.parents[y]
    self.parents[y] = x
  def members(self, x):
    root = self.root(x)
    return [i for i in range(self.n) if self.root(i) == root]
  def groups(self):
    group_members = collections.defaultdict(list)
    for member in range(self.n):
      group_members[self.root(member)].append(member)
    return group_members
  def size(self, x): return -self.parents[self.root(x)]
  def same(self, x, y): return self.root(x) == self.root(y)
  def roots(self): return [i for i, x in enumerate(self.parents) if x < 0]
  def group_count(self): return len(self.roots())
  def __str__(self): return '\n'.join(f'{r}: {m}' for r, m in self.groups().items())
# UnionFind ここまで

n, m = LI()
d = LI()

graph = [[] for _ in range(n)]

uf = UnionFind(n)

for _ in range(m):
  a, b = LI()
  a -= 1
  b -= 1
  graph[a].append(b)
  graph[b].append(a)
  uf.unite(a, b)

group_edge = []
for (k, v) in uf.groups().items():
  edges = []
  for i in v:
    count = d[i] - len(graph[i])
    if count == 0: continue
    if count < 0:
      print(-1)
      exit()
    for _ in range(count):
      edges.append(i)
  group_edge.append(edges)

deg1 = []
deg2 = []
for group in group_edge:
  if len(group) == 1: deg1.extend(group)
  elif len(group) >= 2: deg2.append(group)
  else:
    print(-1)
    exit()

ans = []
for group in deg2:
  for v in range(len(group) - 1):
    if len(deg1) == 0:
      print(-1)
      exit()
    uf.unite(group[v], deg1[-1])
    ans.append((group[v], deg1[-1]))
    deg1.pop()
  deg1.append(group[-1])


if len(deg1) != 2:
  print(-1)
  exit()

uf.unite(deg1[0], deg1[1])
ans.append((deg1[0], deg1[1]))

if uf.size(0) != n or len(ans) != n - m - 1:
  print(-1)
  exit()

for (a, b) in ans:
  print(a + 1, b + 1)
