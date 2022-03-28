import bisect,collections,copy,heapq,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())

n, k = LI()
a = LI()

sum = 0
x = 0

# そのままやる

if k <= n:
  for i in range(k):
    sum += a[x]
    x += a[x % n]
    x %= n
  print(sum)
  exit()

# 周期性を使う

init = (-1, -1)
# history[i] = [(loop, score)]
history = [(-1, -1)] * n
for i in range(k):
  sum += a[x]
  x += a[x % n]
  x %= n
  if history[x] != init:
    loop, score = history[x]
    sum_diff = sum - score
    loop_size = i - loop
    sum += sum_diff * ((k - i - 1) // loop_size)
    for _ in range((k - i - 1) % loop_size):
      sum += a[x]
      x += a[x % n]
      x %= n
    break
  history[x] = (i, sum)

print(sum)

