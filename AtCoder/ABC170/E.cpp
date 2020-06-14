#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007LL // = 10^9 + 7

using namespace std;
using ll = long long;

using Pair = pair<int, int>;
#define A first
#define Belong second

void solve()
{
	int n, q;
	cin >> n >> q;
	vector<Pair> infant(n);

	int max_score[200001];
	fill(max_score, max_score + 200001, -1);

	int a, b;
	for(int i = 0; i < n; ++i)
	{
		cin >> a >> b;
		infant[i] = make_pair(a, b);
		max_score[b] = max(max_score[b], a);
	}

	for(const auto& v : infant)
	{
		cout << v.Belong << " ";
	}


	int c, d;
	for(int i = 0; i < q; ++i)
	{
		cout << endl << i << " : -------" << endl;

		cin >> c >> d;
		c--;

		int before = infant[c].Belong;
		int after = d;

		infant[c].Belong = d;

		for(const auto& v : infant)
		{

		}

		/*
		最小の幼稚園に、その値よりも大きいレートを持つ幼児が移ったとき、答えが変わる
		幼稚園の最大のレートを持つ幼児が移るとき、答えが変わるかもしれない
		ans = min(各幼稚園のレート)
		各幼稚園のレート = max(各幼児のレート)

		ans = min(dp[0], dp[1], dp[2],...)
		dp[i] = infant[0]
		
		*/


		for(const auto& v : infant)
		{
			cout << v.Belong << "," << v.A << " ";
		}


	}
}

int main()
{
	fastio;
	solve();

	return 0;
}