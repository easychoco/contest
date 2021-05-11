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
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }

void solve()
{
  ll n, m, q;
  cin >> n >> m >> q;
  vector<tuple<ll, ll>> ss(n);
  rep(i, n)
  {
    ll w, v;
    cin >> w >> v;
    ss[i] = make_tuple(v, w);
  }

  sort(RALL(ss));

  vector<ll> x(m);
  rep(i, m) cin >> x[i];

  rep(qi, q)
  {
    ll l, r;
    cin >> l >> r;
    l--; r--;

    vector<ll> xx;
    rep(i, m)
    {
      if (l <= i && i <= r) continue;
      xx.emplace_back(x[i]);
    }

    sort(ALL(xx));
    
    ll ans = 0;
    rep(si, n)
    {
      ll v, w;
      tie(v, w) = ss[si];
      rep(xi, (ll)xx.size())
      {
        if (xx[xi] >= w)
        {
          xx[xi] = -10;
          ans += v;
          break;
        }
      }
    }
    show(ans);
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}