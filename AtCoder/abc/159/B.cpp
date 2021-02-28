#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

bool isOk(string s)
{
	bool ret = true;
	int n = s.length();
	for(int i = 0; i < n / 2; ++i)
	{
		ret = ret & (s[i] == s[n - i - 1]);
	}
	// cout << "in " << s << " " << ret << endl;
	return ret;
}

void solve()
{
	string s;
	cin >> s;
	int n = s.length();
	bool ans = true;
	ans = 	isOk(s) & 
			isOk(s.substr(0, (n - 1) / 2)) & 
			isOk(s.substr( (n + 3) / 2 - 1));

	cout << ( ans ? "Yes" : "No") << endl;
}

int main()
{
	fastio;
	solve();

	return 0;
}