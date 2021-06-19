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
    vec[i] = lower_bound(ALL(ret), vec[i]) - ret.begin();
  }

  return ret;
}

void solve()
{
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n)
  {
    cin >> a[i];
  }

  compress(a);
  vector<ll> hist(n + 1, 0);

  rep(i, n)
  {
    hist[a[i]]++;
  }

  ll ans = 0;
  rep(i, n)
  {
    ans += (n - hist[a[i]] - i);
    hist[a[i]]--;
  }
  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}