#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

void solve()
{
	int n, m;
	cin >> n >> m;
	vector< vector< pair<int, int> > > a(n);
	vector<int> ans(m, 0);

	queue< vector< pair<int, int> > > que;

	for(int i = 0; i < m; ++i)
	{
		int in_a, in_b;

		cin >> in_a >> in_b;
		in_a--;
		in_b--;

		a[in_a].push_back(make_pair(in_a, in_b));
		a[in_b].push_back(make_pair(in_b, in_a));
	}

	que.push(a[0]);
	while(!que.empty())
	{
		vector< pair<int, int> > vec = que.front();
		que.pop();
		for(const auto& v : vec)
		{
			if (ans[v.second] == 0)
			{
				ans[v.second] = v.first + 1;
				que.push(a[v.second]);
			}
		}
	}

	// No の判定もする
	bool isOk = true;
	for (int i = 1; i < n; ++i)
	{
		isOk = (isOk & (ans[i] != 0));
	}

	if (isOk)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
		return;
	}
	
	for(int i = 1 ;i < n; ++i)
	{
		cout << ans[i] << endl;
	}

}

int main()
{
	fastio;
	solve();

	return 0;
}