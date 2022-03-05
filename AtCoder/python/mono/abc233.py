import bisect,collections,copy,heapq,itertools,math,string,operator
from functools import reduce
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())

def a():
  x, y = LI()
  print((y - x - 1) // 10 + 1 if x < y else 0)

def b():
  l, r = LI()
  l -= 1
  s = S()
  s1 = s[:l]
  s2 = s[l:r][::-1]
  s3 = s[r:]
  print(s1 + s2 + s3)

def c():
  n, x = LI()
  a = []
  for _ in range(n):
    _a = LI()
    a.append(_a[1:])

  ans = 0
  for pro in itertools.product(*a):
    p = 1
    for num in pro:
      p *= num
      if p > x: break
    if p == x: ans += 1
  print(ans)

def d():
  n, k = LI()
  a = LI()
  
  now, ans = 0, 0
  mp = collections.defaultdict(lambda: 0)
  mp[0] = 1
  for i in a:
    now += i
    ans += mp[now - k]
    mp[now] += 1

  print(ans)

def e():
  x = S()
  sz = len(x)
  digit = [0]
  digit.extend([int(i) for i in x])
  for i in range(sz):
    digit[i + 1] += digit[i]

  for i in reversed(range(1, sz + 1)):
    if digit[i] >= 10:
      digit[i - 1] += digit[i] // 10
      digit[i] %= 10

  if digit[0] == 0: digit = digit[1:]
  print("".join([str(i) for i in digit]))


# a()
# b()
# c()
# d()
e()
