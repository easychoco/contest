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

bool ok[1000][1000];

struct Edge{ char c; ll to; };
void solve()
{
  ll n, m;
  cin >> n >> m;
  vector< vector<Edge> > graph(n, vector<Edge>());
  rep(i, m)
  {
    ll a, b;
    char c;
    cin >> a >> b >> c;
    a--; b--;
    graph[a].emplace_back(Edge{c, b});
    graph[b].emplace_back(Edge{c, a});
  }

  queue<tuple<string, ll, ll>> que;
  que.emplace("", 0, n - 1);
  while(!que.empty())
  {
    string str;
    ll from0, fromn;
    tie(str, from0, fromn) = que.front();
    que.pop();

    if(ok[from0][fromn]) continue;
    ok[from0][fromn] = true;
    if ((int)str.length() > n * 2) break;

    vector<vector<ll>> cv0(26, vector<ll>(0)), cvn(26, vector<ll>(0));
    for(auto e : graph[from0])
    {
      ll to = e.to;
      char c = e.c;
      cv0[(int)(c - 'a')].emplace_back(to);
      // show(from0, "->", to);
      if (to == fromn)
      {
        show(str.length() * 2 + 1);
        return;
      }
    }
    for(auto e : graph[fromn])
    {
      ll to = e.to;
      char c = e.c;
      cvn[(int)(c - 'a')].emplace_back(to);
      // show(fromn, "->", to);
      if (to == from0)
      {
        show(str.length() * 2 + 1);
        return;
      }
    }
    rep(i, 26)
    {
      for(auto to0 : cv0[i])
      for(auto ton : cvn[i])
      {
        string ns = str + (char)(i + 'a');
        // show(cv0[i].size(), cvn[i].size(), ":", ns, from0, "->", to0, ",", fromn, "->", ton);
        if (to0 == ton)
        {
          show(ns.length() * 2);
          return;
        }
        que.emplace(ns, to0, ton);
      }
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