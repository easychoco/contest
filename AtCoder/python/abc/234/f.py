import bisect,collections,copy,heapq,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())

# nCr % mod を計算する O(r)
def combmod(n, r, mod):
  x, y = 1, 1
  r = min(n - r, r)
  for i in range(r): x = x * (n - i) % mod # 分子
  for i in range(1, r + 1): y = y * i % mod # 分母
  return x * pow(y, mod - 2, mod) % mod; # nCr = (分子) * (分母)^-1 mod M

m = 998244353

s = S()
sz = len(s)

hist = [0] * 26
for c in s:
  hist[ord(c) - ord('a')] += 1

# dp[i][j] = これまでに j 文字選んだときの組み合わせ
dp = [0] * (sz + 1)
dp[0] = 1
for i in range(26):
  if hist[i] == 0: continue
  nx = copy.deepcopy(dp)
  for num in range(1, hist[i] + 1):
    for j in range(sz):
      # num 文字選んで、合計で j + num 文字になる
      if j + num > sz: continue
      nx[j + num] += dp[j] * combmod(j + num, num, m)
      # print(j, num, dp[j], ' * ', combmod(j + num, num, m))
      nx[j + num] %= m
  dp = copy.deepcopy(nx)

ans = 0
for i in range(1, sz + 1):
  ans += dp[i]
  ans %= m

print(ans)