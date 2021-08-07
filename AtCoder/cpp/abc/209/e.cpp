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

constexpr ll MAX_N = 52 * 52 * 52;

ll char_to_ll(char c)
{
  if (isupper(c)) return c - 'A';
  return c - 'a' + 26;
}

ll string_to_ll(char a, char b, char c)
{
  return 
    char_to_ll(a) * 52 * 52 + 
    char_to_ll(b) * 52 + 
    char_to_ll(c);
}

void solve()
{
  ll n;
  cin >> n;
  vector<P> edge(n);
  vvl rev(MAX_N);
  vl cnt(MAX_N, 0); // このワードの出次数 / rev での入次数
  rep(i, n)
  {
    string s;
    cin >> s;
    ll sz = s.length();
    ll from = string_to_ll(s[0], s[1], s[2]);
    ll to   = string_to_ll(s[sz - 3], s[sz - 2], s[sz - 1]);
    edge[i] = make_pair(from, to);
    cnt[from]++;
    rev[to].emplace_back(from);
  }

  // 端点は負け
  // (移動先は相手の状態)
  // 負けの頂点にいけるなら勝ち
  // 勝ちの頂点だけにいけるなら負け
  // 引き分けと勝ちの頂点にいけるなら引き分け
  // 引き分けと負けの頂点にいけるなら勝ち

  //  0: 負け
  //  1: 勝ち
  // -1: 引き分け

  vl ans(MAX_N, -1);
  queue<int> que;
  rep(i, MAX_N)
  {
    if (cnt[i] == 0) // 端点からスタートする
    {
      ans[i] = 0;
      que.push(i);
    }
  }
  while(!que.empty())
  {
    ll to = que.front();
    que.pop();
    for (ll from : rev[to])
    {
      // もう決まっているということは勝ちの頂点
      if (ans[from] != -1) continue;

      cnt[from]--;

      if (ans[to] == 0)
      {
        // 負けの頂点に行けるなら勝ち
        ans[from] = 1;
        que.push(from);
      }
      else if (cnt[from] == 0)
      {
        // 更新されていない = 勝ちの頂点だけに行けるなら負け
        ans[from] = 0;
        que.push(from);
      }
    }
  }

  rep(i, n)
  {
    ll to = edge[i].second;
    if (ans[to] == -1) show("Draw");
    if (ans[to] ==  0) show("Takahashi");
    if (ans[to] ==  1) show("Aoki");
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}
