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

// 全探索する
// 制約から、全通り試しても 10^5 なので大丈夫
// L の数が決まっていないので再帰でやる
// オーバーフローがこわいので int128 をつかった

ll n, x;
vvl a;
ll ans = 0;
void dfs(__int128 now, ll depth)
{
  if (now > x) return;
  if (n <= depth)
  {
    if (now == x) ans++;
    return;
  }

  ll sz = a[depth].size();
  rep(i, sz)
  {
    dfs(now * a[depth][i], depth + 1);
  }
}

void solve()
{
  cin >> n >> x;
  a.resize(n);
  rep(i, n)
  {
    ll cnt;
    cin >> cnt;
    a[i].resize(cnt);
    rep(j, cnt)
    {
      cin >> a[i][j];
    }
  }
  dfs(1, 0);
  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}
