#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i = a;i < (ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define SHOW(str,val) cout<<(str)<<" : "<<(val)<<endl;

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// using P = pair<int, int>;
void YN(bool a) { cout << (a ? "Yes" : "No"); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true;} return false;}

void solve()
{
  ll n, m, v, p;
  cin >> n >> m >> v >> p;
  p--;
  vector<ll> a(n), b(n);
  rep(i, n) cin >> a[i];
  sort(RALL(a));
  b[0] = a[0];
  repi(i, 1, n)
  {
    b[i] = b[i - 1] + a[i];
  }

  auto f = [&](ll arg)
  {
    // V箇所に投票 -> (N-V)箇所を減算
    // (N-V)箇所を1ずつ減らしていって、a[arg]がa[p]以上になる回数を返す
    if (a[arg] >= a[p]) return 0LL;

    ll sum = 0;
    if (p == 0) sum = b[arg];
    else sum = b[arg] - b[p - 1];
    sum -= a[arg] * (arg - p + 1);
    ll ret = max(a[p] - a[arg], (sum - 1LL) / (n - v) + 1LL);
    return ret;
  };

  ll le = 0, re = n;
  while(re - le > 1)
  {
    ll mid = (le + re) / 2;
    if ( f(mid) > m ) re = mid;
    else le = mid;
  }

  cout << le + 1;
}

int main()
{
  fastio;
  solve();

  return 0;
}