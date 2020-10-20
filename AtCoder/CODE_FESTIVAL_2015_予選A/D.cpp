#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i = a;i < (ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define SHOW(str,val) cout<<(str)<<" : "<<(val)<<endl;

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// using P = pair<int, int>;
void YN(bool a) { cout << (a ? "Yes" : "No"); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true;} return false;}

void solve()
{
  ll n, m;
  cin >> n >> m;
  vector<ll> x(m);
  rep(i, m)
  {
    cin >> x[i];
    x[i];
  }

  vector<ll> a(m + 1);
  a[0] = x[0] - 1;
  repi(i, 1, m)
  {
    a[i] = x[i] - x[i - 1] - 1;
  }
  a[m] = n - x[m - 1];

  auto f = [&](ll arg)
  {
    ll over = 0;
    rep(i, m)
    {
      if (a[i] - over <= 0) over = arg;
      else if (a[i] - over <= arg)
      {
        // 左にいってから右
        ll lr = arg - (a[i] - over) * 2;
        
        // 右にいってから左
        ll rl = (arg - (a[i] - over)) / 2;
        over = max(lr , rl);

      }
      else
      {
        return false;
      }
    }
    return a[m] <= over;
  };

  ll wa = -1, ac = 1e9 + 5e8;
  while(ac - wa > 1)
  {
    ll wj = (ac + wa) / 2;
    if ( !f(wj) ) wa = wj;
    else ac = wj;
  }

  cout << ac << endl;

}

int main()
{
  fastio;
  solve();

  return 0;
}