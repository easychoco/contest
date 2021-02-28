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
  ll n, m, p, q, r;
  cin >> n >> m >> p >> q >> r;
  vector< vector<P> > wom(n, vector<P>());
  rep(i, r)
  {
    ll x, y, z;
    cin >> x >> y >> z;
    x--; y--;
    wom[x].emplace_back(z, y);
  }

  // 女子 n / p人
  // 男子 m / q人

  ll ans = 0;
  repi(bit, (1<<p) - 1, 1<<n)
  {
    bitset<20> mask(bit);
    if (mask.count() != p) continue;

    vector<int> hist(m, 0);
    ll score = 0;
    rep(i, n)
    {
      if (mask[i])
      {
        for(const auto& pa : wom[i]) hist[pa.second] += pa.first;
      }
    }

    sort(RALL(hist));
    rep(i, q) score += hist[i];
    chmax(ans, score);
  }
  cout << ans << endl;
}

int main()
{
  fastio;
  solve();

  return 0;
}