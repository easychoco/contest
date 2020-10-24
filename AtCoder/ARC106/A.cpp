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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

void solve()
{
  ll n;
  cin >> n;
  ll thr = 3;
  ll cnt_3 = 0;
  for(thr; thr <= n; thr *= 3)
  {
    cnt_3++;
    ll cnt_5 = 0;
    for(ll fiv = 5; thr + fiv <= n; fiv *= 5)
    {
      cnt_5++;
      if (thr + fiv == n)
      {
        cout << cnt_3 << " " << cnt_5 << endl;
        return;
      }
    }
  }
  cout << -1;
}

int main()
{
  fastio;
  solve();

  return 0;
}