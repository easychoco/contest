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

void solve()
{
  ll n;
  cin >> n;
  map<ll, P> mp;
  rep(i, n){
    ll x, c;
    cin >> x >> c;
    if (mp.find(c) == mp.end()) mp[c] = P(x, x);
    else
    {
      chmin(mp[c].first, x);
      chmax(mp[c].second, x);
    }
  }
  mp[0] = P(0, 0);

  // dp[i][j] = i 番目の ボールまで見て、 j の端で終わった時の最小コスト
  // j = 0 : 左端, 1 : 右端
  vector< vector<ll> > dp(mp.size(), vector<ll>(2, 1LL << 60));
  dp[0][0] = dp[0][1] = 0;

  ll i = 0;
  ll ple = 0;
  ll pre = 0;
  for(auto m : mp)
  {
    P p = m.second;
    ll le = p.first;
    ll re = p.second;

    if (i > 0)
    {
      dp[i][0] = re - le + min(dp[i - 1][0] + abs(ple - re), dp[i - 1][1] + abs(pre - re));
      dp[i][1] = re - le + min(dp[i - 1][0] + abs(ple - le), dp[i - 1][1] + abs(pre - le));
    }

    ple = le;
    pre = re;
    i++;
  }

  // 残りは座標 0 に戻って終了
  show(min(dp.back()[0] + abs(ple), dp.back()[1] + abs(pre)));
}

int main()
{
  fastio;
  solve();

  return 0;
}