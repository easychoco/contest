// https://atcoder.jp/contests/abc167/submissions/me
#include <bits/stdc++.h>
#include <atcoder/all>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=(a);i<(ll)(n);++i)
#define repe(i,n) repie(i,0,n)
#define repie(i,a,n) for(ll i=(a);i<=(ll)(n);++i)
#define rrep(i,n) rrepi(i,n,0)
#define rrepi(i,n,a) for(ll i=(n);i>=(a);--i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using namespace atcoder;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using P = pair<ll, ll>;
const ll INF = 1LL << 60;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }

void solve()
{
  ll n, m, x;
  cin >> n >> m >> x;
  vector<ll> c(n);
  vvl a(n, vl(m));
  rep(i, n)
  {
    cin >> c[i];
    rep(j, m) cin >> a[i][j];
  }

  ll ans = INF;
  rep(bit, 1 << n)
  {
    vector<ll> score(m, 0);
    ll cost = 0;
    rep (i, n)
    {
      if (bit >> i & 1)
      {
        cost += c[i];
        rep(j, m)
        {
          score[j] += a[i][j];
        }
      }
    }

    bool ok = true;
    rep(i, m)
    {
      ok &= (score[i] >= x);
    }
    if (ok) chmin(ans, cost);
  }
  if (ans == INF) ans = -1;
  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}
