v, a, b, c = map(int, input().split())

v %= (a + b + c)
v -= a
if v < 0:
  print('F')
  exit()
v -= b
if v < 0:
  print('M')
  exit()
print('T')
  