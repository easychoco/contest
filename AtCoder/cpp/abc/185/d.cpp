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
  vector<ll> a(m + 1);
  a[0] = 0;
  rep(i, m)
  {
    cin >> a[i + 1];
  }
  a.emplace_back(n + 1);

  sort(ALL(a));

  ll k = 1'000'000'000;
  vector<ll> b(m + 1);
  rep(i, m + 1)
  {
    b[i] = max(0LL, a[i + 1] - a[i] - 1);
    if (b[i] > 0) chmin(k, b[i]);
  }

  ll ans = 0;
  for(const auto& v : b)
  {
    if (v <= 0) continue;
    ans += (v - 1) / k + 1;
  }
  Showln(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}