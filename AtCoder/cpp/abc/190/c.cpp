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
  vector<ll> a(m), b(m);
  rep(i, m)
  {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }

  ll k;
  cin >> k;
  vector<ll> c(k), d(k);
  rep(i, k)
  {
    cin >> c[i] >> d[i];
    c[i]--; d[i]--;
  }

  ll ans = 0;
  rep(mask, 1LL << k)
  {
    vector<ll> hist(n, 0);
    rep(i, k)
    {
      if ((mask & (1LL << i)) > 0) hist[c[i]]++;
      else hist[d[i]]++;
    }
    ll score = 0;
    rep(i, m)
    {
      if (hist[a[i]] > 0 && hist[b[i]] > 0) score++;
    }
    chmax(ans, score);
  }
  Show(ans);

}

int main()
{
  fastio;
  solve();

  return 0;
}