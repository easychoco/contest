#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
	ll n, m, b, c;
  cin >> n >> m;
  map<ll, ll> a;
  ll input;
  for(int i = 0; i < n; ++i)
  {
    cin >> input;
    a[input]++;
  }
  
  for(int i = 0; i < m; ++i)
  {
    cin >> b >> c;
    int loop_cnt = 0;
    for(auto& val : a)
    {
      if (val.first >= c) break;

      if (val.second > b)
      {
        a[c] += b;
        val.second -= b;
        break;
      }

      loop_cnt++;
      b -= val.second;
      a[c] += val.second;
      val.second = 0;
    }
    a.erase(begin(a), next(begin(a), loop_cnt));
  }

  ll ans = 0;
  for(auto& val : a)
  {
    ans += (val.first * val.second);
  }
  cout << ans;
}

int main()
{
	fastio;
	solve();

	return 0;
}