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

// 座標圧縮 O (N log N)
// 破壊的なので注意
// 戻り値は重複を削除 ( sort & unique ) した vector
template <typename T>
vector<T> compress(vector<T> &vec)
{
  vector<T> ret = vec;

  // 重複削除
  sort(ALL(ret));
  ret.erase(unique(ALL(ret)), ret.end());

  // 各要素ごとに二分探索で位置を求める
  rep (i, vec.size())
  {
    vec[i] = lower_bound(ALL(ret), ret[i]) - ret.begin();
  }

  return ret;
}

ll mx;
vector<ll> c(100010, 0);
vector< vector<ll> > edge(100010, vector<ll>());

vector<ll> ans(0);
vector<ll> mask(100010, 0);
vector<bool> come(100010, false);

void dfs(ll now)
{
  if (come[now]) return;
  come[now] = true;

  if (mask[c[now]] == 0) ans.emplace_back(now);
  mask[c[now]]++;

  for(auto next : edge[now])
  {
    dfs(next);
  }

  mask[c[now]]--;
}

void solve()
{
  ll n;
  cin >> n;
  rep(i, n)
  {
    cin >> c[i];
  }

  rep(i, n - 1)
  {
    ll a, b;
    cin >> a >> b;
    a--; b--;
    edge[a].emplace_back(b);
    edge[b].emplace_back(a);
  }

  dfs(0);

  sort(ALL(ans));
  for(auto a : ans)
  {
    show(a + 1);
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}
