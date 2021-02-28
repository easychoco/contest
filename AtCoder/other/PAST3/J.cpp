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
	ll n, m, a;
  cin >> n >> m;
  vector<ll> child(n, 1e9);
  rep(i, m)
  {
    cin >> a;
    a = 1e9 - a;
    auto pos = upper_bound(ALL(child), a);
    if (pos == child.end()) cout << -1 << endl;
    else
    {
      cout << distance(child.begin(), pos) + 1 << endl;
      *pos = a;
    }    
  }
}

int main()
{
	fastio;
	solve();

	return 0;
}