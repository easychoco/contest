import bisect,collections,copy,heapq,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())

# https://atcoder.jp/contests/abc117/tasks/abc117_d
n, k = LI()
a = LI()

ans = 0

digit = 1
while digit <= k:
  digit *= 2
digit //= 2

x = 0
while digit > 0:
  cnt = 0
  for v in a:
    if (v & digit) > 0: cnt += 1
  if cnt <= n // 2 and x + digit <= k: x += digit
  digit //= 2

ans = 0
for v in a:
  ans += v ^ x
print(ans)

'''
# https://atcoder.jp/contests/arc060/tasks/arc060_a
n, a = LI()
x = LI()
total = sum(x)

# dp[x][y] = x 個選んで和が y になる組み合わせ
dp = [[0] * (total + 1) for _ in range(n + 1)]
dp[0][0] = 1

for v in x:
  for i in reversed(range(n)):
    for j in range(total - v + 1):
      dp[i + 1][j + v] += dp[i][j]

ans = 0
for i in range(1, n + 1):
  if a * i > total: break
  ans += dp[i][a * i]

print(ans)
'''