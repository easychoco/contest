# import bisect,collections,copy,heapq,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())

n, q = LI()
s = S()
query = [LS() for x in range(q)]

le = -1
re = n
for (pos, com) in reversed(query):
  if re - 1 >= 0 and s[re - 1] == pos and com == 'R':
    re -= 1
  if re < n and s[re] == pos and com == 'L':
    re += 1
  if le >= 0 and s[le] == pos and com == 'R':
    le -= 1
  if le + 1 < n and s[le + 1] == pos and com == 'L':
    le += 1

print(re - le - 1)
