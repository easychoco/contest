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
  ll n;
  string s;
  cin >> n >> s;
  int ans = n;

  string st;
  rep(i, n)
  {
    st += s[i];
    int len = st.length();
    if (len >= 3 && st.substr(len - 3, 3) == "fox")
    {
      ans -= 3;
      st = st.substr(0, len - 3);
    }
  }
  cout << ans << endl;
}

int main()
{
  fastio;
  solve();

  return 0;
}