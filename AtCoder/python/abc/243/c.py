import collections
n = int(input())
xy = []
for i in range(n):
  xy.append(map(int, input().split()))

s = input()

pos = collections.defaultdict(list)
for i, (x, y) in enumerate(xy):
  pos[y].append((x, s[i]))

def trans(xy):
  x, y = xy
  return y

for d in pos.values():
  d.sort()
  t = ''.join(list(map(trans, d)))
  if 'RL' in t:
    print('Yes')
    exit()

print('No')
