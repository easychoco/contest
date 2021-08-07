#include<iostream>
#include<algorithm>
#include<string>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

char ToUpper (char c) { return toupper(c); }

void solve()
{
	string s, t;
	cin >> s >> t;
	if (s == t)
	{
		cout << "same";
		return;
	}

	transform(s.begin(), s.end(), s.begin(), ToUpper);
	transform(t.begin(), t.end(), t.begin(), ToUpper);

	if (s == t)
	{
		cout << "case-insensitive";
	}
	else
	{
		cout << "different";
	}
	
}

int main()
{
	fastio;
	solve();

	return 0;
}