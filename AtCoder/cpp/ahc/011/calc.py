import bisect,collections,copy,heapq,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())

nums = []

args = sys.argv
for _ in range(int(args[1])):
  s = LS()
  nums.append(int(s[2]))

print("max:", max(nums))
print("min:", min(nums))
print("ave:", sum(nums)/len(nums))
print("sum:", sum(nums))
