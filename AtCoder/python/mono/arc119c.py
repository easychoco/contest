import bisect,collections,copy,heapq,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())

# (l, r) の範囲が 11 の倍数なら答えとして数える。
# 11 の倍数かどうかを判定する問題になる。
# ABC233-E が似ている
# 判定方法 -> https://yeah-education.com/blog_maths/11baisuu/
# zero-sum-range を使えば高速に判定できる

n = I()
a = LI()
d = collections.defaultdict(int)
d[0] = 1
sum = 0
for i in range(0, n, 2):
  sum += a[i]
  d[sum] += 1
  if i + 1 < n: 
    sum -= a[i + 1]
    d[sum] += 1

ans = 0
for key in d:
  num = d[key]
  ans += num * (num - 1) // 2
print(ans)
