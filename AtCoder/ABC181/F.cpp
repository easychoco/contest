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
  ll n, xi, yi;
  cin >> n;
  vector<tuple<ll, ll>> pos(n);
  vector<tuple<ll, ll>> mid_pos;
  rep(i, n)
  {
    cin >> xi >> yi;
    pos[i] = make_tuple(xi, yi);
  }

  rep(i, n-1) repi(j, i+1, n)
  {
    ll x1, y1, x2, y2;
    tie(x1, y1) = pos[i];
    tie(x2, y2) = pos[j];
    mid_pos.emplace_back((x1 + x2) / 2, (y1 + y2) / 2);
  }
  
}

int main()
{
  fastio;
  solve();

  return 0;
}