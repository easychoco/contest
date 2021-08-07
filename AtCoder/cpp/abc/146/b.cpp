#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;


void solve()
{
	int n;
	string s;
	cin >> n >> s;
	
	for(auto& c : s)
	{
		char ch = (((c + n) - 'A') % 26 + 'A');
		cout << ch;
	}
}

int main()
{
	fastio;
	solve();

	return 0;
}