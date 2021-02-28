#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	for(int i = 0; i < h; ++i)
	{
		cin >> s[i];
	}
	vector< vector<int> > runlength_h(h, vector<int>(1, 1));
	for(int y = 0; y < h; ++y)
	{
		for(int x = 1; x < w; ++x)
		{
			if (s[y][x-1] == s[y][x]) runlength_h[y].back() += 1;
			else runlength_h[y].emplace_back(1);
		}
	}
	vector< vector<int> > runlength_w(w, vector<int>(1, 1));
	for(int x = 0; x < w; ++x)
	{
		for(int y = 1; y < h; ++y)
		{
			if (s[y][x] == s[y-1][x]) runlength_w[x].back() += 1;
			else runlength_w[x].emplace_back(1);
		}
	}

	int ans = 0;
	vector< vector<int> > score(h, vector<int>(w, 0));
	for(int y = 0; y < h; ++y)
	{
		int index = 0;
		for(const int& r : runlength_h[y])
		{
			for(int i = index; i < index + r; ++i) score[y][i] += r;
			index += r;
		}
	}
	for(int x = 0; x < w; ++x)
	{
		int index = 0;
		for(const int& r : runlength_w[x])
		{
			for(int i = index; i < index + r; ++i) score[i][x] += r;
			index += r;
		}
	}
	
	for(int y = 0; y < h; ++y)
	{
		for(int x = 0; x < w; ++x)
		{
			if (s[y][x] == '.') 
			{
				score[y][x]--;
				ans = max(ans, score[y][x]);
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