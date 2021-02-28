#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;


void solve()
{
	string s;
	cin >> s;
	s += 'R';

	int r_cnt = 0;
	int l_cnt = 0;
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == 'R')
		{
			r_cnt++;
		}
		else if (s[i] == 'L')
		{
			l_cnt++;
		}
		if (s[i] =='L' && s[i + 1] == 'R')
		{
			for(int i = 0; i < r_cnt - 1; ++i) cout << "0 ";
			cout << (r_cnt + 1) / 2 +  l_cnt      / 2 << " ";
			cout <<  r_cnt      / 2 + (l_cnt + 1) / 2 << " ";
			for(int i = 0; i < l_cnt - 1; ++i) cout << "0 ";

			r_cnt = 0;
			l_cnt = 0;
		}
	}
}

int main()
{
	fastio;
	solve();

	return 0;
}