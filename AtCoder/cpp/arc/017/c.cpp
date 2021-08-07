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
  ll n, x;
  cin >> n >> x;
  
  vector<ll> a(n / 2), aw;
  vector<ll> b((n + 1) / 2), bw;
  rep(i, n / 2) cin >> a[i];
  rep(i, (n + 1) / 2) cin >> b[i];
  
  rep(mask, 1 << a.size())  
  {
    ll w = 0;
    rep(i, a.size())
    {
      if (mask >> i & 1) w += a[i];
    }
    aw.emplace_back(w);
  }

  rep(mask, 1 << b.size())  
  {
    ll w = 0;
    rep(i, b.size())
    {
      if (mask >> i & 1) w += b[i];
    }
    bw.emplace_back(w);
  }

  sort(ALL(aw));
  sort(ALL(bw));

  ll ans = 0;
  for(const auto& w : aw)
  {
    auto litr = lower_bound(ALL(bw), x - w);
    auto uitr = upper_bound(ALL(bw), x - w);
    if (litr != uitr)
    {
      ans += distance(litr, uitr);
    }
  }

  cout << ans << endl;
}

int main()
{
  fastio;
  solve();

  return 0;
}