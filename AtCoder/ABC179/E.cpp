#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using ll = long long;

const double PI = 3.14159265358979;

void solve()
{
  ll n, x, m;
  cin >> n >> x >> m;
  vector<ll> rep(m, -1LL);
  vector<ll> sum;
  ll sum_all = 0;

  ll lp = 0;
  while(rep[x] == -1)
  {
    rep[x] = lp;
    lp++;
    sum.emplace_back(x);
    sum_all += x;
    x = (x * x) % m;
  }


  ll loop_cnt = lp - rep[x];
  ll sum_loop = 0;
  for(int i = rep[x]; i < lp; ++i) sum_loop += sum[i];

  ll ans = 0;
  if (n <= lp)
  {
    for(int i = 0; i < n; ++i) ans += sum[i];
  }
  else
  {
    ans += sum_all;
    n -= lp;
    ans += sum_loop * (n / loop_cnt);
    n %= loop_cnt;
    for(int i = 0; i < n; ++i) ans += sum[rep[x] + i];
  }  
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}