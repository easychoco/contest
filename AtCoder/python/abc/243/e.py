n, m = map(int, input().split())
inf = 1001001001001
dist = [[inf] * n for _ in range(n)]
orig = [[inf] * n for _ in range(n)]
for _ in range(m):
  a, b, c = map(int, input().split())
  a -= 1
  b -= 1
  dist[a][b] = c
  dist[b][a] = c
  orig[a][b] = c
  orig[b][a] = c

ans = 0
for k in range(n):
  for i in range(n):
    for j in range(n):
      if dist[i][j] >= dist[i][k] + dist[k][j]:
        dist[i][j] = dist[i][k] + dist[k][j]
        dist[j][i] = dist[i][k] + dist[k][j]
        if orig[i][j] < inf:
          ans += 1
          orig[i][j] = inf
          orig[j][i] = inf
print(ans)