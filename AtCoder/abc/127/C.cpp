#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
	int n, m, l, r;
  cin >> n >> m;
  int imos[100005];
  fill(imos, imos + 100005, 0);
  for(int i = 0; i < m; ++i)
  {
    cin >> l >> r;
    imos[l]++;
    imos[r + 1]--;    
  }

  int ans = 0;
  for(int i = 0; i < 100004; ++i)
  {
    imos[i + 1] += imos[i];
    if(imos[i + 1] == m) ans++;
  }
  cout << ans;
}

int main()
{
	fastio;
	solve();

	return 0;
}