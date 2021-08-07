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
  int x;
  cin >> x;

  vector<bool> dp(x + 110, false);
  dp[0] = true;
  int y[6] = {100, 101, 102, 103, 104, 105};
  for(int i = 0; i <= x; ++i)
  {
    if (dp[i])
    {
      for(const auto& v : y) dp[i + v] = true;
    }
  }
  cout << (int)dp[x];
}

int main()
{
  fastio;
  solve();

  return 0;
}