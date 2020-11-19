// https://atcoder.jp/contests/agc020/tasks/agc020_b
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
  ll k;
  cin >> k;
  vector<ll> a(k);
  rep(i, k) cin >> a[i];

  ll min_n = 2;
  ll max_n = 2;
  for(int i = k - 1; i >= 0; --i)
  {
    if (min_n % a[i] == 0) min_n = a[i] * (min_n / a[i]);
    else min_n = a[i] * (min_n / a[i] + 1);
    max_n = a[i] * (max_n / a[i] + 1) - 1;  
  }

  ll ch_min = min_n;
  rep(i, k) ch_min -= (ch_min % a[i]);
  if (ch_min != 2)
  {
    cout << -1 << endl;
    return;
  }
  
  Show(min_n); Showln(max_n);
}

int main()
{
  fastio;
  solve();

  return 0;
}