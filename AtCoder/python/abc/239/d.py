import bisect,collections,copy,heapq,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())

def isPrime(n):
  if n <= 1: return False
  if n <= 3: return True
  i = 2
  while i * i <= n:
    if n % i == 0: return False
    i += 1
  return True

a, b, c, d = LI()

for taka in range(a, b + 1):
  ok =  True
  for aoki in range(c, d + 1):
    ok &= not isPrime(taka + aoki)
  if ok:
    print('Takahashi')
    exit()

print('Aoki')
