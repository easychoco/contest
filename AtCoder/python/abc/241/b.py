n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

ok_cnt = 0
for ai in range(n):
  for bi in range(m):
    if a[ai] == b[bi]:
      a[ai] = -100
      b[bi] = -101
      ok_cnt += 1
      break

if ok_cnt == m:
  print('Yes')
else:
  print('No')