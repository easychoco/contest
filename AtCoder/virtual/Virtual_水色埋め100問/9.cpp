// https://atcoder.jp/contests/dwacon5th-prelims/tasks/dwacon5th_prelims_b
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
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<ll> sub;
  rep(i, n)
  {
    ll sum = 0;
    repi(j, i, n)
    {
      sum += a[j];
      sub.emplace_back(sum);
    }
  }

  // bit は桁ごとに見るのが定石
  vector<ll> sub_and(sub);
  for(ll b = 40; b >= 0; --b) // 2^40 ~= 10^12
  {
    vector<ll> next;
    for(const auto& v : sub_and)
    {
      if (v & (1LL<<b)) next.emplace_back(v);
    }
    if (next.size() >= k) sub_and = next;
  }
  
  ll ans = sub_and[0];
  for(const auto& v : sub_and) ans &= v;
  cout << ans << endl;
}

int main()
{
  fastio;
  solve();

  return 0;
}