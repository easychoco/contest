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
  string s, x;
  cin >> n >> s >> x;

  reverse(ALL(s));
  vector<ll> num(n);
  ll log = 1;
  rep(i, n)
  {
    num[i] = ((int)(s[i] - '0') * log) % 7;
    log *= 10;
  }

  reverse(ALL(s));
  reverse(ALL(num));

  // dp[i] = mod が i になるか
  vector<bool> dp(7, false);


  ll las_num = 1;
  for(int i = n - 1; i >= 1; --i)
  {
    if (x[i] == x[i - 1]) las_num++;
    else break;
  }

  dp[0] = true;
  dp[num[0]] = true;
  rep(i, n - las_num)
  {
    vector<bool> next(7, false);
    rep(ii, 7) if (dp[ii]) next[(dp[ii] + num[i]) % 7] = true;

    dp = next;
  }

  vector<bool> dpp(7, false);
  dpp[0] = true;
  dpp[num[n - las_num]] = true;
  repi(i, n - las_num, n)
  {
    vector<bool> next(7, false);
    rep(ii, 7) if (dpp[ii]) next[(dpp[ii] + num[i]) % 7] = true;

    dpp = next;
  }

  // A : x7 はダメ
  // T : x7 にしたい
  if (s.back() == 'A')
  {
    rep(i, 7)
    rep(ii, 7)
    if (dp[i] + dpp[ii] != 0)
    {
      cout << "Aoki" << endl;
      return;
    }
    cout << "Takahashi" << endl;
  }
  else
  {
    rep(i, 7)
    rep(ii, 7)
    if (dp[i] + dpp[ii] == 0)
    {
      cout << "Takahashi" << endl;
      return;
    }
    cout << "Aoki" << endl;
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}