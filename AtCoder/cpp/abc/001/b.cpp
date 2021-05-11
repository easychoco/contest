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
  ll m;
  cin >> m;
  
  if (m < 100) cout << "00" << endl;
  else if (m <= 5000)
  {
    if (m < 1000) cout << 0 << m / 100 << endl;
    else cout << m / 100 << endl;
  }
  else if (m <= 30000)
  {
    cout << m / 1000 + 50 << endl;
  }
  else if (m <= 70000)
  {
    cout << (m - 30000) / 5000 + 80 << endl;
  }
  else
  {
    cout << 89 << endl;
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}