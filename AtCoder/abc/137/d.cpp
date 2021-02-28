#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

using P = pair<int, int>;

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<P> job(n);

	for(int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		job[i] = P(a, b);
	}

	sort(job.begin(), job.end());
	priority_queue<int> job_score;

	ll ans = 0;
	int job_index = 0;
	for(int i = 1; i <= m; ++i)
	{
		while(job_index < n && job[job_index].first <= i)
		{
			job_score.push(job[job_index].second);
			job_index++;
		}
		if (!job_score.empty())
		{
			ans += job_score.top();
			job_score.pop();
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