#include <bits/stdc++.h>
#include <atcoder/all>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=a;i<(ll)n;++i)
#define repe(i,n) repie(i,0,n)
#define repie(i,a,n) for(ll i=a;i<=(ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<ll, ll>;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }

// dp[i][j] = i 番目まで見て j 日目のときの最大報酬値
ll dp[5010][5010];

void solve()
{
  ll n;
  cin >> n;
  vector< tuple<ll, ll, ll> > task(n);

  rep(i, n)
  {
    ll d, c, s;
    cin >> d >> c >> s;
    task[i] = make_tuple(d, c, s);
  }

  sort(ALL(task));
  rep(i, n)
  {
    ll d, c, s;
    tie(d, c, s) = task[i];
    rep(day, 5000)
    {
      if (day + c <= d) chmax(dp[i + 1][day + c], dp[i][day] + s);
      chmax(dp[i + 1][day], dp[i][day]);
    }
  }
  ll ans = 0;
  repe(i, 5000) chmax(ans, dp[n][i]);
  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}