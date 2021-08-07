#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
	int n, k;
  cin >> n >> k;

  double ans = max(0, n - k + 1);
  for(int i = 1; i <= min(n, k - 1); ++i)
  {
    double prob = pow( 2, (int)( -0.0000001 - ceil( log(k / (double)i) / log(2) ) ) );
    ans += prob;
  }
  printf("%.10f\n", ans / (double)n);
}

int main()
{
	fastio;
	solve();

	return 0;
}