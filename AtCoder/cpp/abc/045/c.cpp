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
  string s;
  cin >> s;
  ll nn = (1LL << (s.length() - 1));
  ll ans = 0;
  rep(i, nn)
  {
    ll tmp = 0;
    ll pos = 0;
    rep(j, s.length() - 1)
    {
      if (i & (1LL<<j))
      {
        tmp += stoll(s.substr(pos, j-pos+1));
        pos = j + 1;
      }
    }
    ll sz= s.length();
    tmp += stoll(s.substr(pos, sz - pos + 1));
    ans += tmp;
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}