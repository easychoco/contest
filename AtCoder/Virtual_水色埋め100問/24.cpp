// https://atcoder.jp/contests/abc047/tasks/arc063_b
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
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll idx_min = 0;
  ll idx_max = 0;

  // tuple<score, min_idx>
  set<tuple<ll, ll>> st;
  ll sc_max = 0;
  rep(i, n)
  {
    if (a[i] <= a[idx_min])
    {
      idx_min = i;
      idx_max = i;
    }
    if (a[idx_max] <= a[i])
    {
      idx_max = i;
    }
    
    if(sc_max <= a[idx_max] - a[idx_min])
    {
      st.insert(make_tuple(a[idx_max] - a[idx_min], idx_min));
      sc_max = a[idx_max] - a[idx_min];
    }
  }

  ll ans = 0;
  for(const auto& s : st)
  {
    if (get<0>(s) == sc_max) ans++;
  }

  cout << ans << endl;
}

int main()
{
  fastio;
  solve();

  return 0;
}