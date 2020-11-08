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
  ll n, x;
  cin >> n >> x;
  vector<ll> a(n);
  rep(i, n)
  {
    cin >> a[i];
  }

  ll ans = 0;
  set<ll> mod;
  for(int i = 1; i < n - 1; ++i)
  {
    if (x % a[i] == 0) continue;
    ll num = x * a[i];
    mod.insert((x + a[i]) % x);
    Show(x + a[i]);
  }
  Showln("");
  rep(i, n)
  {
    ll num = a[i] * ((x - 1) / a[i] + 1);
    Show(num);
    mod.insert(num % x);
  }
  Showln("");

  repi(i, 1, n) repi(j, 1, i)
  {
    // a[i] = 100, a[j] = 4
    if (a[i] * ((x - a[j] - 1) / a[i] + 1) >= x) continue;
    ll num = a[j];
    num += a[i] * ((x - a[j] - 1) / a[i] + 1);
    Show(num);
    mod.insert(num % x);
  }
  Showln("");
  cout << mod.size();
}

int main()
{
  fastio;
  solve();

  return 0;
}