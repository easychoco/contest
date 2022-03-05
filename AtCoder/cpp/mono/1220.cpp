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

class UnionFind{
public:
  vector<ll> p;		// 親
  vector<ll> rank;	// サイズ・各集合の根のみ有効
  ll root_num; // 連結成分の数
  UnionFind(ll n) : root_num(n) {
    p.resize(n, -1);
    rank.resize(n, 1);
  }
  ll root(ll x){
    if(p[x] == -1) return x;
    else return p[x] = root(p[x]); // 深さを 1 にしている
  }
  bool unite(ll x, ll y){
    x = root(x); y = root(y);
    if(x == y) return false;
    if(rank[x] > rank[y]) swap(x, y); // rankの小さいものを下につける
    rank[y] += rank[x];
    p[x] = y;
    root_num--;
    return true;
  }
  // グループごとに頂点をまとめる: O(N log N)
  map<ll, vector<ll>> groups(){
    map<ll, vector<ll>> ret;
    rep(i, p.size()) ret[root(i)].emplace_back(i);
    return ret;
  }
  //xが属すグループのサイズ
  ll size(ll x){ return rank[root(x)]; }
  bool same(ll x, ll y){ return (root(x) == root(y)); }
};

// https://atcoder.jp/contests/arc097/tasks/arc097_b
void solve()
{
  ll n, m;
  cin >> n >> m;
  vl p(n + 1);
  rep(i, n) cin >> p[i];
  UnionFind uf(n + 1);
  rep(i, m)
  {
    ll x, y;
    cin >> x >> y;
    uf.unite(x, y);
  }
  
  ll ans = 0;
  rep(i, n)
  {
    if (uf.same(i + 1, p[i]))
    {
      ans++;
    }
  }
  show(ans);
}

/*
// https://atcoder.jp/contests/abc178/tasks/abc178_e
void solve()
{
  ll n;
  cin >> n;
  vp pos(n);
  rep(i, n)
  {
    ll x, y;
    cin >> x >> y;
    pos[i] = make_pair(x + y, x - y);
  }

  vl x;
  vl y;
  rep(i, n)
  {
    x.push_back(pos[i].first);
    y.push_back(pos[i].second);
  }

  ll ans = 0;
  auto itr_x = minmax_element(ALL(x));
  auto itr_y = minmax_element(ALL(y));
  ans = max(*(itr_x.second) - *(itr_x.first), *(itr_y.second) - *(itr_y.first));
  show(ans);
}
*/

/*
// https://atcoder.jp/contests/abc191/tasks/abc191_c
void solve()
{
  ll h, w;
  cin >> h >> w;
  vector<string> mp(h);
  rep(i, h) cin >> mp[i];

  ll ans = 0;
  rep(y, h - 1)
  rep(x, w - 1)
  {
    // (y, x) の左上が角かどうか
    string up = "";
    up += mp[y][x];
    up += mp[y][x + 1];
    string dn = "";
    dn += mp[y + 1][x];
    dn += mp[y + 1][x + 1];

    string ck = up + dn;
    if (!(
      ck == "...." ||
      ck == "####" ||
      ck == ".#.#" ||
      ck == "#.#." ||
      ck == "..##" ||
      ck == "##.."  
    )) 
    ans++;
  }
  show(ans);
}
//*/

/*
// https://atcoder.jp/contests/abc161/tasks/abc161_e
void solve()
{
  ll n, k, c;
  string s;
  cin >> n >> k >> c >> s;

  vl ans;
  vector<bool> show(n, false);
  // たくさん働くのと、できるだけ働かないのの共通部分
  ll cnt = 0;
  rep(i, n)
  {
    if (s[i] == 'o')
    {
      show[i] = true;
      i += c;
      cnt++;
    }
    if (cnt >= k) return;
  }
  cnt = 0;
  rrep(i, n - 1)
  {
    if (s[i] == 'o')
    {
      if (show[i]) ans.emplace_back(i + 1);
      i -= c;
      cnt++;
    }
    if (cnt >= k) break;
  }
  sort(ALL(ans));
  showall(ans);
}
//*/

/*
// https://atcoder.jp/contests/abc174/tasks/abc174_e
void solve()
{
  ll n, k;
  cin >> n >> k;
  vl a(n);
  rep(i, n) cin >> a[i];

  // 長さ arg にすることができる
  auto f = [&](ll arg) -> bool
  {
    ll cnt = 0;
    rep(i, n)
    {
      cnt += (a[i] - 1) / arg;
    }
    return cnt <= k;
  };
  ll wa = 0, ac = 1'000'000'001LL;
  while(ac - wa > 1)
  {
    ll wj = (ac + wa) / 2;
    if ( f(wj) ) ac = wj;
    else wa = wj;
  }
  show(ac);
}
//*/

int main()
{
  fastio;
  solve();

  return 0;
}
