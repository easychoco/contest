#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

class ABCD
{
public:
	ABCD(){}
	ABCD(int _a, int _b, int _c, int _d)
	{
		a = _a;
		b = _b;
		c = _c;
		d = _d;
	}
	int a;
	int b;
	int c;
	int d;
};

vector<ABCD> vec;
int n, m, q;

int calcScore(long long int in)
{
	int score = 0;

	int seq[10] = {};
	for(int i = 0; i < n; ++i)
	{
		seq[i] = in % 10;
		in /= 10;
	}

	for(auto v : vec)
	{
		if ((seq[v.a] - seq[v.b]) == v.c)
		{
			score += v.d;
		}
	}
	return score;
}

int dfs(long long int a, int log)
{
	if (log <= 0)
	{
		return calcScore(a);
	}

	int score = 0;
	for(long long int i = a % 10; i < m; ++i)
	{
		long long int next = a * 10 + i;
		score = max(score, dfs(next, log - 1));
	}
	return score;
}

void solve()
{
	cin >> n >> m >> q;
	vec = vector<ABCD>(q);

	for (int i = 0; i < q; ++i)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		// convert a, b to "0 base index".
		vec[i] = ABCD(a - 1, b - 1, c, d);
	}

	cout << dfs(0, n) << endl;
}

int main()
{
	solve();

	return 0;
}