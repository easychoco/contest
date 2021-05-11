// https://atcoder.jp/contests/agc039/tasks/agc039_b
#include <bits/stdc++.h>

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
  ll n;
  cin >> n;
  vector< vector<int> > g(n, vector<int>());

  const ll INF = 100100100100;
  const int N = 200;
  ll d[N][N];
  rep(i, N) rep(j, N) d[i][j] = INF;
  rep(i, N) d[i][i] = 0;

  rep(i, n)
  {
    string s;
    cin >> s;
    rep(j, n) if(s[j] == '1')
    {
      g[i].emplace_back(j);
      d[i][j] = 1;
    }
  }

  rep (k, n){       // 経由する頂点
    rep (i, n) {    // 始点
      rep (j, n) {  // 終点
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  map<string, vector<ll>> grp;
  rep(i, n)
  {
    string key = "";
    rep(j, n) key += ((d[i][j] % 2) + '0');
    grp[key].emplace_back(i);
  }

  if (grp.size() > 2)
  {
    cout << -1 << endl;
    return;
  }

  auto grp_itr = grp.begin();
  vector<ll> gr1 = grp_itr->second;
  ++grp_itr;
  vector<ll> gr2 = grp_itr->second;

  /*
  for(auto v : gr1) Show(v);
  Showln("");
  for(auto v : gr2) Show(v);
  */
 
  int ans = 0;
  rep(i, n)
  {
    // tuple<now, depth>
    queue<tuple<int, int>> que;
    vector<bool> seen(n, false);

    que.emplace(i, 1);
    while(!que.empty())
    {
      int now, depth;
      tie(now, depth) = que.front();
      que.pop();

      if (seen[now]) continue;
      seen[now] = true;

      chmax(ans, depth);
      for(const auto& next : g[now])
      {
        if (seen[next]) continue;
        que.emplace(next, depth + 1);
      }
    }
  }

  cout << ans << endl;
}

int main()
{
  fastio;
  solve();

  return 0;
}