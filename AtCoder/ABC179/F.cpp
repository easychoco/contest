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
  ll n, q, a, x;
  cin >> n >> q;

  ll min_h = n - 2;
  ll min_w = n - 2;
  vector<ll> h(n - 2, min_w), w(n - 2, min_h);

  ll white = 0;
  rep(i, q)
  {
    cin >> a >> x;
    x -= 2;
    if (a == 1)
    {
      if (x < min_w)
      {
        repi(i, x, min_w) h[i] = min_h;
        min_w = x;
      }
      white += h[x];
    }
    else
    {
      if (x < min_h)
      {
        repi(i, x, min_h) w[i] = min_w;
        min_h = x;
      }
      white += w[x];
    }
  }

  cout << (n - 2) * (n - 2) - white;
}

int main()
{
  fastio;
  solve();

  return 0;
}