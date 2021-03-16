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
using ll = int;
using P = pair<ll, ll>;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }

bool dp[200010][7];

void solve()
{
  ll n;
  string s, x;
  cin >> n >> s >> x;

  // A : x7 はダメ
  // T : x7 はOK

  // dp[i][res] = iラウンド目が終了したときに7で割った余りが res のとき、ここからゲームを続けるとTakahashiが勝つ
  dp[n][0] = true;
  for(int i = n - 1; i >= 0; --i)
  {
    rep(res, 7)
    {
      bool add0 = dp[i + 1][(res * 10) % 7];
      bool adds = dp[i + 1][(res * 10 + (ll)(s[i] - '0')) % 7];
      dp[i][res] = (x[i] == 'A') ? (add0 & adds) : (add0 | adds);
    }
  }
  cout << (dp[0][0] ? "Takahashi" : "Aoki") << endl;
}

int main()
{
  fastio;
  solve();

  return 0;
}