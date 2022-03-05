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

/*
グラフでやると O((H + W) * N) で解けない。DP で解く。
aの大きい順に見ていって、答えを更新しながらグリッドの状態を更新する
グリッドは 200000 * 200000 なので、全部を配列で持つのはできない。

ある点が (y, x) にあるとき、 y 行と x 列の値のうち、自分よりも値が大きいものだけが関係ある。
-> 値が大きいものから順に扱えば良い。
また、そのなかの答えが最大値のもの +1 が次の値の答えになる。
だから、y 行と x 列の最大値が高速に分かればいい。これは map かな。
*/
void solve()
{
  ll h, w, n;
  cin >> h >> w >> n;

  // mp[a] = vector< tuple<r, c, index> >
  map<ll, vector<tuple<ll, ll, ll>>> mp;
  rep(i, n)
  {
    ll r, c, a;
    cin >> r >> c >> a;
    mp[a].emplace_back(r, c, i);
  }

  vl ans(n, 0);
  map<ll, ll> maxy; // maxy[y] = y行の最大値
  map<ll, ll> maxx; // maxx[x] = x行の最大値

  // a の値が大きい順に処理する
  for (auto itr = mp.rbegin(); itr != mp.rend(); ++itr)
  {
    for (auto [r, c, i] : itr->second)
    {
      ans[i] = max({ans[i], maxy[r], maxx[c]});
    }

    // 同じ値が複数あるときに壊れるので、答えの更新と最大値の更新を分けている
    for (auto [r, c, i] : itr->second)
    {
      chmax(maxy[r], ans[i] + 1);
      chmax(maxx[c], ans[i] + 1);
    }
  }  

  showall(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}
