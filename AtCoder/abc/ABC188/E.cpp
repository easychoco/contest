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
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector< vector<ll> > edge(n, vector<ll>());
  rep(i, m)
  {
    ll x, y;
    cin >> x >> y;
    x--; y--;
    edge[x].emplace_back(y);
  }

  ll ans = -(1LL << 60);
  vector<ll> minv(a);
  rep(i, n)
  {
    for(const auto& to : edge[i])
    {
      chmax(ans, a[to] - minv[i]);
      chmin(minv[to], min(minv[i], a[to]));
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