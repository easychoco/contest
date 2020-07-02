#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
	int n, p;
	string s;
	cin >> n;
	map<string, vector<P>> rest;
	for(int i = 0; i < n; ++i)
	{
		cin >> s >> p;
		rest[s].emplace_back(P(p, i + 1));
	}
	for(const auto& r : rest)
	{
		auto vec = r.second;
		sort(vec.begin(), vec.end());
		for(auto it = vec.rbegin(); it != vec.rend(); ++it)
		{
			cout << it->second << endl;
		}
	}
}

int main()
{
	fastio;
	solve();

	return 0;
}