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

def toIdx(y, x): return y * 10 + x

mp = []
for _ in range(10):
  mp.append(S())
  # print(mp[-1])


uf = UnionFind(10 * 10 + 1)
for y in range(10):
  for x in range(10):
    if x < 9:
      if mp[y][x] == 'o' and mp[y][x + 1] == 'o':
        u1 = toIdx(y, x)
        u2 = toIdx(y, x + 1)
        uf.unite(u1, u2)
    if y < 9:
      if mp[y][x] == 'o' and mp[y + 1][x] == 'o':
        u1 = toIdx(y, x)
        u2 = toIdx(y + 1, x)
        uf.unite(u1, u2)

for y in range(10):
  for x in range(10):
    if mp[y][x] == 'x': uf.unite(toIdx(y, x), 100)

root_num = uf.group_count() - 1
for y in range(10):
  for x in range(10):
    if mp[y][x] == 'o': continue
    roots = []
    if x > 0 and mp[y][x - 1] == 'o': roots.append(uf.root(toIdx(y, x - 1)))
    if x < 9 and mp[y][x + 1] == 'o': roots.append(uf.root(toIdx(y, x + 1)))
    if y > 0 and mp[y - 1][x] == 'o': roots.append(uf.root(toIdx(y - 1, x)))
    if y < 9 and mp[y + 1][x] == 'o': roots.append(uf.root(toIdx(y + 1, x)))
    # print(y, x, mp[y][x + 1], mp[y + 1][x], len(set(roots)), root_num)
    if len(set(roots)) == root_num:
      print('YES')
      exit()
print('NO')
