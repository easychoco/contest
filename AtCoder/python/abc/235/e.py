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
  def all_group_members(self):
    group_members = defaultdict(list)
    for member in range(self.n):
      group_members[self.root(member)].append(member)
    return group_members
  def size(self, x): return -self.parents[self.root(x)]
  def same(self, x, y): return self.root(x) == self.root(y)
  def roots(self): return [i for i, x in enumerate(self.parents) if x < 0]
  def group_count(self): return len(self.roots())
  def __str__(self): return '\n'.join(f'{r}: {m}' for r, m in self.all_group_members().items())
# UnionFind ここまで

n, m, q = LI()
uf = UnionFind(n)

graph = []
query = []
for _ in range(m):
  a, b, c = LI()
  a -= 1
  b -= 1
  graph.append((c, a, b))
for i in range(q):
  u, v, w = LI()
  u -= 1
  v -= 1
  query.append((w, u, v, i))

graph.sort()
query.sort()

qi = 0
ans = ['No'] * q
for (cost, a, b) in graph:
  while qi < q and query[qi][0] <= cost:
    w, u, v, i = query[qi]
    if not uf.same(u, v): ans[i] = 'Yes'
    qi += 1
  uf.unite(a, b)

for a in ans:
  print(a)
