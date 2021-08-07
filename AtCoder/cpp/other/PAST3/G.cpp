#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;
using Pair = pair<int, int>;

int grid[405][405] = {};
const int BLOCK = 200000000;
const int INIT  = 150000000;
const int DEST  = 100000000;

int grid_pair(const Pair p)
{
	return grid[p.first][p.second];
}

void set_grid_pair(const Pair p, int num)
{
	grid[p.first][p.second] = num;
}

void solve()
{
	for(int i = 0; i < 405; ++i)
	{
		for(int j = 0; j <= 405; ++j)
		{
			grid[i][j] = INIT;
		}
	}

	int n, dest_x, dest_y;
	cin >> n >> dest_x >> dest_y;
	dest_x += 202;
	dest_y += 202;
	grid[dest_x][dest_y] = DEST;	

	for(int i = 0; i < n; ++i)
	{
		int x, y;
		cin >> x >> y;
		x += 202;
		y += 202;
		grid[x][y] = BLOCK;
	}

	queue<Pair> que;

	grid[202][202] = 0;
	que.push(make_pair(202, 202));

	int dx[6] = { 1, 0, -1, 1, -1,  0};
	int dy[6] = { 1, 1,  1, 0,  0, -1};

	int cnt = 0;
	while(!que.empty())
	{
		Pair p = que.front();
		que.pop();
		for(int i = 0; i < 6; ++i)
		{
			Pair next_p = make_pair(p.first + dx[i], p.second + dy[i]);

			if (next_p.first < 0 || next_p.first > 404 || next_p.second < 0 || next_p.second > 404)
			{
				continue;
			}

			if (grid_pair(next_p) == INIT)
			{
				set_grid_pair(next_p, grid_pair(p) + 1);
				que.push(next_p);
			}
			else if (grid_pair(next_p) == DEST)
			{
				cout << grid_pair(p) + 1;
				return;
			}
		}
	}
	cout << -1;
}

int main()
{
	fastio;
	solve();

	return 0;
}