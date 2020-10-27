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
  ll n, k, w, p;
  cin >> n >> k;
  vector<P> sw(n);
  rep(i, n) 
  {
    cin >> w >> p;
    sw[i] = P(p, w);
  }

  sort(RALL(sw));

  vector<bool> used(n, false);
  ll water = 0, salt = 0;
  water = sw[0].second * (100 - sw[0].first);
  salt = sw[0].first * sw[0].second;
  used[0] = true;
  repi(kk, 1, k)
  {
    ll nw = 0;
    ll ns = 0;
    double score = 0.0;
    ll index = 0;
    repi(i, 1, n)
    {
      if (used[i]) continue;
      
      ll tw = sw[i].second * (100 - sw[i].first);
      ll ts = sw[i].first * sw[i].second;
      double tscore = (salt + ts) / (double)(salt + water + ts + tw);
      if (chmax(score, tscore))
      {
        nw = tw;
        ns = ts;
        index = i;
      }
    }
    water += nw;
    salt += ns;
    used[index] = true;
  }
  printf("%.9lf\n", 100 * salt / (double)(salt + water));
}

int main()
{
  fastio;
  solve();

  return 0;
}