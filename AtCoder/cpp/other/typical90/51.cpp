#include <bits/stdc++.h>
#include <atcoder/all>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=a;i<(ll)n;++i)
#define repe(i,n) repie(i,0,n)
#define repie(i,a,n) for(ll i=a;i<=(ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }

void solve()
{
  ll n, k, p;
  cin >> n >> k >> p;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vvl sum(41);
  ll sz = min(n, 20LL);
  rep(mask, 1 << sz)
  {
    ll s = 0;
    ll cnt = 0;
    rep(i, sz)
    {
      if (mask >> i & 1)
      {
        s += a[i];
        cnt++;
      }
    }
    sum[cnt].emplace_back(s);
  }

  if (n <= 20)
  {
    ll ans = 0;
    for(auto& s : sum[k])
    {
      if (s <= p) ans++;
    }
    show(ans);
    return;
  }

  vvl sum2(41);
  sz = n - 20;
  rep(mask, 1 << sz)
  {
    ll s = 0;
    ll cnt = 0;
    rep(i, sz)
    {
      if (mask >> i & 1)
      {
        s += a[20 + i];
        cnt++;
      }
    }
    sum2[cnt].emplace_back(s);
  }

  rep(i, sz) sort(ALL(sum2[i]));

  ll ans = 0;
  repe(i, k)
  {
    for(auto& s : sum[i])
    {
      ans += upper_bound(ALL(sum2[k - i]), p - s) - sum2[k - i].begin();
    }
  }
  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}