#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

void solve()
{
	array<string, 5> s0 = 
	{
		"###",
		"#.#",
		"#.#",
		"#.#",
		"###",
	};
	array<string, 5> s1 = 
	{
		".#.",
		"##.",
		".#.",
		".#.",
		"###",
	};
	array<string, 5> s2 = 
	{
		"###",
		"..#",
		"###",
		"#..",
		"###",
	};
	array<string, 5> s3 = 
	{
		"###",
		"..#",
		"###",
		"..#",
		"###",
	};
	array<string, 5> s4 = 
	{
		"#.#",
		"#.#",
		"###",
		"..#",
		"..#",
	};
	array<string, 5> s5 = 
	{
		"###",
		"#..",
		"###",
		"..#",
		"###",
	};
	array<string, 5> s6 = 
	{
		"###",
		"#..",
		"###",
		"#.#",
		"###",
	};
	array<string, 5> s7 = 
	{
		"###",
		"..#",
		"..#",
		"..#",
		"..#",
	};
	array<string, 5> s8 = 
	{
		"###",
		"#.#",
		"###",
		"#.#",
		"###",
	};
	array<string, 5> s9 = 
	{
		"###",
		"#.#",
		"###",
		"..#",
		"###",
	};

	int n;
	string s[5];
	cin >> n >> s[0] >> s[1] >> s[2] >> s[3] >> s[4] >> s[5];

	for(int i = 0; i < n; ++i)
	{
		array<string, 5> num 
		{
			s[0].substr(4 * i + 1, 3),
			s[1].substr(4 * i + 1, 3),
			s[2].substr(4 * i + 1, 3),
			s[3].substr(4 * i + 1, 3),
			s[4].substr(4 * i + 1, 3),
		};

		if (num == s0) cout << 0;
		if (num == s1) cout << 1;
		if (num == s2) cout << 2;
		if (num == s3) cout << 3;
		if (num == s4) cout << 4;
		if (num == s5) cout << 5;
		if (num == s6) cout << 6;
		if (num == s7) cout << 7;
		if (num == s8) cout << 8;
		if (num == s9) cout << 9;
	}
}

int main()
{
	fastio;
	solve();

	return 0;
}