#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

#define X first
#define Y second

using Pair = pair<int, int>;
const int BLOCK = 100000;

void solve()
{
	int h, w;
	cin >> h >> w;

	int ans = 0;

	vector< vector<int> > initial_maze( h, vector<int>(w, -1) );

	string s;
	for(int i = 0; i < h; ++i)
	{
		cin >> s;
		for(int j = 0; j < w; ++j)
		{
			initial_maze[i][j] = ((s[j] == '.') ? -1 : BLOCK);
		}
	}

	for(int i = 0; i < w; ++i)
	{
		for(int j = 0; j < h; ++j)
		{
			if (initial_maze[j][i] == BLOCK)
			{
				continue;
			}
			vector< vector<int> > maze( initial_maze );

			queue<Pair> que;
			Pair p(make_pair(i, j));
			maze[j][i] = max(0, maze[j][i]);
			que.push(p);

			int dx[4] = { 0, 1, 0, -1 };
			int dy[4] = { 1, 0, -1, 0 };

			while(!que.empty())
			{
				Pair now = que.front();
				que.pop();

				for(int k = 0; k < 4; ++k)
				{
					int next_x = now.X + dx[k];
					int next_y = now.Y + dy[k];
					if (next_x < 0 || w <= next_x || next_y < 0 || h <= next_y)
					{
						continue;
					}

					if (maze[next_y][next_x] == -1)
					{
						Pair next(make_pair(next_x, next_y));
						maze[next.Y][next.X] = maze[now.Y][now.X] + 1;
						que.push(next);
					}
				}
			}

			for(int y = 0; y < h; ++y)
			{
				for(int x = 0; x < w; ++x)
				{
					if (maze[y][x] != BLOCK)
					{
						ans = max(ans, maze[y][x]);
					}
				}
			}
		}
	}
	cout << ans;
}

int main()
{
	fastio;
	solve();

	return 0;
}