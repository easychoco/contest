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

int n, a;
vector<ll> x;
array<ll, 5001> hist_f, hist_b;

void dfs(ll val, int idx, int max_idx)
{
  if (idx == max_idx)
  {
    if (max_idx == n) hist_b[val + n * a]++;
    else hist_f[val + n * a]++;
    return;
  }

  dfs(val, idx + 1, max_idx);
  dfs(val + x.at(idx), idx + 1, max_idx);
}

void solve()
{
  cin >> n >> a;
  x = vector<ll>(n);
  rep(i, n)
  {
    cin >> x[i];
    x[i] -= a;
  }

  hist_f.fill(0);
  hist_b.fill(0);

  dfs(0, 0, n / 2);
  dfs(0, n / 2, n);

  ll ans = 0;
  rep(i, 5001)
  {
    ll num_f = i - n * a;
    ll bi = -num_f + n * a;
    if (bi < 0) break;
    ans += hist_f.at(i) * hist_b.at(bi);
  }
  cout << ans - 1;
}

int main()
{
  fastio;
  solve();

  return 0;
}