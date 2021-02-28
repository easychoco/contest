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
  ll n, t;
  cin >> n >> t;
  ll sz1 = n / 2, sz2 = n - sz1;
  vector<ll> a1(sz1), a2(sz2);
  rep(i, sz1) cin >> a1[i];
  rep(i, sz2) cin >> a2[i];

  vector<ll> sum1, sum2;
  rep(mask, 1 << sz1)
  {
    ll sum = 0;
    rep(i, sz1) if (mask>>i&1) sum += a1[i];
    sum1.emplace_back(sum);
  }
  rep(mask, 1 << sz2)
  {
    ll sum = 0;
    rep(i, sz2) if (mask>>i&1) sum += a2[i];
    sum2.emplace_back(sum);
  }

  sort(ALL(sum2));

  ll ans = sum1[0];
  for(const auto& v : sum1)
  {
    auto itr = upper_bound(ALL(sum2), t - v);
    if (itr == sum2.begin()) continue;
    itr--;
    ll score = v + *itr;
    if (score <= t) chmax(ans, score);
    if (score == t) break;
  }
  cout << ans << endl;
}

int main()
{
  fastio;
  solve();

  return 0;
}