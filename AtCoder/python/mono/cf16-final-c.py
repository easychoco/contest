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
    group_members = collections.defaultdict(list)
    for member in range(self.n):
      group_members[self.root(member)].append(member)
    return group_members
  def size(self, x): return -self.parents[self.root(x)]
  def same(self, x, y): return self.root(x) == self.root(y)
  def roots(self): return [i for i, x in enumerate(self.parents) if x < 0]
  def group_count(self): return len(self.roots())
  def __str__(self): return '\n'.join(f'{r}: {m}' for r, m in self.all_group_members().items())
# UnionFind ここまで


n, m = LI()
valid = set()

p = 0
uf = UnionFind(m)
for _ in range(n):
  k, *l = LI()
  for v in l:
    uf.unite(l[0] - 1, v - 1)
    valid.add(v)
    p = v - 1

print('YES' if uf.size(p) == len(valid) else 'NO')
