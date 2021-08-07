#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=a;i<(ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }


vector<P> sorted;
vector<bool> come(100010, false);
vector< vector<ll> > g;

void dfs(int prev, int now)
{
  if (come[now]) return;
  come[now] = true;

  for (auto& i: g[now]) dfs(now, i);
  // 帰りがけ順で追加
  sorted.push_back(P(prev, now));
};

void solve()
{
  ll n, m;
  cin >> n >> m;
  g = vector< vector<ll> >(n, vector<ll>());
  vector<ll> deg(n, 0); // 入り次数
  rep(i, n + m - 1)
  {
    ll a, b;
    cin >> a >> b;
    a--; b--;
    g[a].emplace_back(b);
    deg[b]++;
  }

  rep(i, n) dfs(-1, i);
  reverse(ALL(sorted));

  vector<P> sorted_;
  vector<bool> come_(n, false);
  queue<P> que;
  que.push(P(sorted[0].second, -1));
  deg[sorted[0].second] = 0;
  while(!que.empty())
  {
    ll now, from;
    tie(now, from) = que.front();
    que.pop();
    sorted_.emplace_back(P(now, from));
    if (come_[now]) continue;
    come_[now] = true;
    for(const auto& to : g[now])
    {
      deg[to]--;
      if (deg[to] == 0) que.push(P(to, now));
    }
  }

  sort(ALL(sorted_));
  rep(i, n)
  {
    show(sorted_[i].second + 1);
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}