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
  ll t, n, a;
  cin >> t;
  rep(ti, t)
  {
    cin >> n;
    ll cnt1 = 0;
    rep(i, n)
    {
      cin >> a;
      if (a == 1) cnt1++;
    }

    // nが奇数:すべて出した後、後手から開始
    if (n&1)
    {
      
    }
    // nが偶数:すべて出した後、先手から開始
    else
    {

    }
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}