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

set<ll> st;

void factor(ll a)
{
  ll ret = 0;
  for(ll i = 1; i*i <= a; ++i)
  {
    if (a % i == 0)
    {
      st.insert(a / i);
      st.insert(i);
    }
  }
}

void solve()
{
  ll n;
  cin >> n;
  // n = i^a * (i*b+1)
  // i = O(√N)
  // a = O(logN)
  // b = O(1)
  // O(√N logN)

  factor(n);
  factor(n - 1);
  st.erase(1);

  ll ans = 0;
  for(const auto f : st)
  {
    ll nn = n;
    while(nn % f == 0) nn /= f;
    if (nn % f == 1) ans++;
  }
  cout << ans;

}

int main()
{
  fastio;
  solve();

  return 0;
}