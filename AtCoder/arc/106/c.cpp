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
  ll n, m;
  cin >> n >> m;
  if (n == 1 && m == 0)
  {
    cout << "1 2\n";
    return;
  }
  if (m < 0 || n - m - 2 < 0)
  {
    cout << -1 << endl;
    return;
  }

  vector<P> ans;
  rep(i, n) ans.emplace_back(2 * i + 1, 2 * i + 2);
  ans[n - m - 2].second = 1e9-1;
  rep(i, n) cout << ans[i].first << " " << ans[i].second << endl;
}

int main()
{
  fastio;
  solve();

  return 0;
}