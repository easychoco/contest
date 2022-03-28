n = int(input())
mp = [input() for _ in range(n)]

def ok():
  print('Yes')
  exit()

for y in range(n):
  for x in range(n):
    # 右
    cnt = 0
    if x + 5 < n:
      for i in range(6):
        if mp[y][x + i] == '#': cnt += 1
      if cnt >= 4: ok()

    # 下
    cnt = 0
    if y + 5 < n:
      for i in range(6):
        if mp[y + i][x] == '#': cnt += 1
      if cnt >= 4: ok()
      
    # 右下
    cnt = 0
    if y + 5 < n and x + 5 < n:
      for i in range(6):
        if mp[y + i][x + i] == '#': cnt += 1
      if cnt >= 4: ok()
    
    # 左下
    cnt = 0
    if y + 5 < n and x - 5 >= 0:
      for i in range(6):
        if mp[y + i][x - i] == '#': cnt += 1
      if cnt >= 4: ok()

        
        
print('No')