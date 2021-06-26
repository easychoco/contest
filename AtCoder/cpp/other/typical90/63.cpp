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
  ll h, w;
  cin >> h >> w;
  vvl p(h, vl(w));
  rep(y, h) rep(x, w) cin >> p[y][x];

  ll ans = 0;
  repi(mask, 1, 1 << h)
  {
    vector<ll> check(w, 0);

    vvl list;
    rep(i, h) if (mask >> i & 1) list.emplace_back(p[i]);

    ll sz = list.size();
    check = list[0];
    rep(x, w)
    {
      repi(i, 1, sz)
      {
        if (list[i][x] != list[0][x])
        {
          check[x] = 0;
        }
      }
    }

    vl hist(80010, 0);
    rep(x, w) hist[check[x]]++;

    ll ans_tmp = 0;
    repi(i, 1, 80010) chmax(ans_tmp, hist[i]);
    ans_tmp *= sz;
    chmax(ans, ans_tmp);
  }
  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}