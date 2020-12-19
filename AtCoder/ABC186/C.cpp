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
  cin >> n;

  vector<bool> hist(n + 1, true);
  for(int i = 1; i <= n; ++i)
  {
    string num = to_string(i);
    for(const auto& c : num) if (c == '7') hist[i] = false;
    stringstream soct;
    soct << std::oct << i;
    for(const auto& c : soct.str()) if (c == '7') hist[i] = false;
  }

  ll ans = 0;
  repi(i, 1, n + 1) ans += hist[i];
  Showln(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}