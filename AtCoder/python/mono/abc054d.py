import bisect,collections,copy,heapq,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())

inf = 1000000

n, ma, mb = LI()
abc = []
for _ in range(n):
  abc.append(LI())

# score[y][x]: a が yグラム, b が xグラムのときの最小コスト
# 後ろから全探索
score = [[inf] * 401 for _ in range(401)]
score[0][0] = 0
for (a, b, c) in abc:
  for y in reversed(range(a, 401)):
    for x in reversed(range(b, 401)):
      score[y][x] = min(score[y][x], score[y - a][x - b] + c)

ans = inf
for v in range(1, 400 // max(ma, mb) + 1):
  ans = min(ans, score[v * ma][v * mb])

if ans == inf: ans = -1
print(ans)