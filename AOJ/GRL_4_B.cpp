#include <bits/stdc++.h>
// Topological Sort
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B&lang=ja

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=a;i<(ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define Show(val) cout<<(val)<<" "
#define Showln(val) cout<<(val)<<endl

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// using P = pair<int, int>;
void YN(bool a) { cout << (a ? "Yes" : "No"); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

void solve()
{
  ll n, m, s, t;
  cin >> n >> m;
  vector< vector<ll> > edge(n, vector<ll>());
  vector<ll> deg(n, 0);
  rep(i, m)
  {
    cin >> s >> t;
    edge[s].emplace_back(t);
    deg[t]++;
  }

  queue<ll> que;
  rep(i, n) if (deg[i] == 0) que.push(i);
  while(!que.empty())
  {
    ll now = que.front();
    que.pop();
    for(const auto& v : edge[now])
    {
      deg[v]--;
      if (deg[v] == 0) que.push(v);
    }    
    cout << now << endl;
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}