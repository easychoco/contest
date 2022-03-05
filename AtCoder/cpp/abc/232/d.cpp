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
using ll = int_fast64_t;
using vl = vector<ll>;
using vvl = vector<vl>;
using P = pair<ll, ll>;
using vp = vector<P>;
using vvp = vector<vp>;
const ll INF = 1LL << 60;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }

ll h, w;
ll to_idx(ll y, ll x)
{
  return y * h + x;
}

void solve()
{
  ll h, w;
  cin >> h >> w;
  vector<string> mp(h);
  rep(i, h) cin >> mp[i];

  vvl score(100, vl(100, 0));
  score[0][0] = 1;

  ll ans = 0;
  rep(y, h)
  rep(x, w)
  {
    if (mp[y][x] == '#') continue;
    if (y > 0) chmax(score[y][x], score[y - 1][x]);
    if (x > 0) chmax(score[y][x], score[y][x - 1]);
    if (y > 0 && x > 0) chmax(score[y][x], score[y - 1][x] + score[y][x - 1]);
    chmin(score[y][x], (ll)1);
    chmax(ans, score[y][x] * (y + x + 1));
  }
  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}
