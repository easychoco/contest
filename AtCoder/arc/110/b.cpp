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
  string t;
  cin >> n >> t;

  ll ans = 0;
  if (n == 1)
  {
    if (t == "1") ans = 2LL * pow(10, 10);
    else ans = pow(10, 10);
    printf("%lld\n", ans);
    return;
  }
  else if (n == 2)
  {
    if (t == "01") ans = pow(10, 10) - 1;
    else if (t == "10") ans = pow(10, 10);
    else if (t == "11") ans = pow(10, 10);
    printf("%lld\n", ans);
    return;
  }

  ll start_pos = 0;
  string sub = t.substr(0, 3);
  if (sub == "110") start_pos = 0;
  else if (sub == "101") start_pos = 1;
  else if (sub == "011") start_pos = 2;
  else
  {
    cout << "0\n";
    return;
  }

  bool ok = true;
  rep(i, n)
  {
    ok &= (t[i] == sub[i % 3]);
  }
  if (!ok)
  {
    cout << "0\n";
    return;
  }

  ll first_end_pos = start_pos + n;

  ans = pow(10, 10) - ((first_end_pos - 1) / 3);
  printf("%lld\n", ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}