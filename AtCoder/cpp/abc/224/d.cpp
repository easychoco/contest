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
効率的な解法が浮かばないので、全探索で解く。
よくわかんないときは全探索でやることがままある。
*/
bool isOk(string s)
{
  bool ok = true;
  rep(i, 9)
  {
    ok &= (s[i] == '-' || s[i] == (i + '0'));
  }
  return ok;
}

void solve()
{
  ll m;
  cin >> m;
  vvl graph(9);
  rep(i, m)
  {
    ll u, v;
    cin >> u >> v;
    u--; v--;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  string s;
  rep(i, 8)
  {
    ll c;
    cin >> c;
    c--;
    s += to_string(c);
  }
  s += '-';

  set<string> shown;
  queue<tuple<string, ll>> que;
  shown.insert(s);
  que.emplace(s, 0);

  while( !que.empty() )
  {
    auto [now, count] = que.front();
    que.pop();

    if (isOk(now))
    {
      show(count);
      return;
    }

    ll from = 0;
    rep(i, 9) if (now[i] == '-') { from = i; break; }

    for (auto to : graph[from])
    {
      string next = now;
      swap(next[from], next[to]);
      auto [_, success] = shown.insert(next);
      if (success) que.emplace(next, count + 1);
    }
  }
  show(-1);
}

int main()
{
  fastio;
  solve();

  return 0;
}
