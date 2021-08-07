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
    sw[i] = P(w, p);
  }

  auto f = [&](double percent)
  {
    vector<double> scores;
    rep(i, n) scores.emplace_back(sw[i].first * ((double)sw[i].second - percent));

    double score = 0.0;    
    sort(RALL(scores));
    rep(i, k) score += scores[i];
    return score >= 0.0;
  };

  double ac = 0.0, wa = 100.0;
  while(wa - ac > 0.000001)
  {
    double wj = (ac + wa) / 2.0;
    if ( !f(wj) ) wa = wj;
    else ac = wj;
  }

  printf("%.9lf\n", ac);
}

int main()
{
  fastio;
  solve();

  return 0;
}