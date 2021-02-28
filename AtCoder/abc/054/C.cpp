#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i = a;i < (ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define SHOW(str,val) cout<<(str)<<" : "<<(val)<<endl;

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// using P = pair<int, int>;
void YN(bool a) { cout << (a ? "Yes" : "No"); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true;} return false;}

void solve()
{
  int n, m, a, b;
  cin >> n >> m;
  vector<ll> edge(n, 0);
  rep(i, m)
  {
    cin >> a >> b;
    a--;
    b--;
    edge[a] |= (1<<b);
    edge[b] |= (1<<a);
  }

  vector<ll> g(n);
  rep(i, n) g[i] = i;
  ll ans = 0;
  do {
    if (g[0] != 0) break;
    bool ok = true;
    for(int i = 0; i < n - 1; ++i) ok &= ((edge[g[i]] & (1 << g[i + 1])) > 0);
    ans += ok;
  } while(next_permutation(ALL(g)));
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}