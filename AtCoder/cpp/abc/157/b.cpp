#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

bool check(int a, int ia)
{
	if ((a & ia) == ia)
	{
		return true;
	}
	return false;
}

void solve()
{
	map<int, int> mp;
	for(int i = 0; i < 9; ++i)
	{
		int a;
		cin >> a;
		mp[a] = i;
	}

	int n;
	cin >> n;
	int ia = 0b000000000;
	for(int i = 0; i < n; ++i)
	{
		int b;
		cin >> b;
		if (mp.find(b) != mp.end())
		{
			ia |= (1 << mp[b]);
		}
	}

	bool ans = false;
	ans |= check(ia, 0b111000000);
	ans |= check(ia, 0b000111000);
	ans |= check(ia, 0b000000111);
	ans |= check(ia, 0b100100100);
	ans |= check(ia, 0b010010010);
	ans |= check(ia, 0b001001001);
	ans |= check(ia, 0b100010001);
	ans |= check(ia, 0b001010100);

	cout << (ans ? "Yes" : "No");
}

int main()
{
	fastio;
	solve();

	return 0;
}