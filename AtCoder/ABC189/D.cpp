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

ll ans[2][63][2];

void solve()
{
  ll n;
  cin >> n;
  string s;

  // ans[i][j][k] = 自分がiの時にj番目の計算をして、数値がkになるものの個数
  ans[0][0][0] = 1;
  ans[0][0][1] = 1;
  ans[1][0][0] = 0;
  ans[1][0][1] = 0;
  repi(i, 1, n + 1)
  {
    cin >> s;
    if (s == "AND")
    {
      ans[0][i][0] = ans[0][i - 1][0] + ans[1][i - 1][0] + ans[0][i - 1][1] + ans[1][i - 1][1];
      ans[1][i][0] = ans[0][i - 1][0] + ans[1][i - 1][0];
      ans[0][i][1] = 0;
      ans[1][i][1] = ans[0][i - 1][1] + ans[1][i - 1][1];
    }
    else // if (s == "OR")
    {
      ans[0][i][0] = ans[0][i - 1][0] + ans[1][i - 1][0];
      ans[1][i][0] = 0;
      ans[0][i][1] = ans[0][i - 1][1] + ans[1][i - 1][1];
      ans[1][i][1] = ans[0][i - 1][0] + ans[1][i - 1][0] + ans[0][i - 1][1] + ans[1][i - 1][1];
    }
  }
  cout << (ans[0][n][1] + ans[1][n][1]) << endl;
}

int main()
{
  fastio;
  solve();

  return 0;
}