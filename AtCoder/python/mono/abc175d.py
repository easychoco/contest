import bisect,collections,copy,heapq,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())

n, k = LI()
p = LI()
c = LI()

for i in range(n): p[i] -= 1

ans = 0 - 10**10

# i からスタートしたときのスコア
for i in range(n):
  # hist[i] = はじめて i にきたときの index
  hist = [-1] * n

  score, now = 0, i
  hist[now] = 0
  for index in range(n):
    now = p[now]
    score += c[now]
    if hist[now] != -1:
      loop_count = index - hist[now] + 1
      loop_score = score
      break
    hist[now] = index

  score, now = 0, i
  if k < 100000:
    for _ in range(k):
      now = p[now]
      score += c[now]
      ans = max(ans, score)
  else:
    for _ in range(k % loop_count + loop_count):
      now = p[now]
      score += c[now]
      ans = max(ans, score)
      if loop_score > 0:
        ans = max(ans, score + loop_score * (k // loop_count - 1))
    
print(ans)
