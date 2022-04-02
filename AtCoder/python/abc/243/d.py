import collections
n, x = map(int, input().split())
s = input()

deq = collections.deque()
for c in s:
  if c == 'U':
    if len(deq) > 0: deq.pop()
    else: x //= 2
  else: deq.append(c)

for c in deq:
  if c == 'L': x *= 2
  if c == 'R': x = x * 2 + 1
  if c == 'U': x //= 2

print(x)