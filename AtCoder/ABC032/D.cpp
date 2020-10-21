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
  ll n, weight;
  cin >> n >> weight;
  vector<ll> v(n), w(n);
  rep(i, n) cin >> v[i] >> w[i];

  if (n <= 30)
  {
    vector<P> a, b;
    rep(mask, 1<<(n/2))
    {
      ll val = 0;
      ll wei = 0;
      rep(i, n/2)
      {
        if (mask>>i&1)
        {
          wei += w[i];
          val += v[i];
        }
      }
      a.emplace_back(P(wei, val));
    }

    rep(mask, 1<<((n+1)/2))
    {
      ll val = 0;
      ll wei = 0;
      rep(i, (n+1)/2)
      {
        if (mask>>i&1)
        {
          wei += w[n/2 + i];
          val += v[n/2 + i];
        }
      }
      b.emplace_back(P(wei, val));
    }

    sort(ALL(a));
    sort(ALL(b));

    // for(const auto& vv : a) cout << vv.first << " ";
    // cout << endl;
    // for(const auto& vv : b) cout << vv.first << " ";
    // cout << endl;

    ll ans = 0;
    rep(i, a.size())
    {
      if (weight - a[i].first >= 0)
      {
        auto b_itr = upper_bound(ALL(b), P(weight - a[i].first, 4e11));
        for(auto itr = b.begin(); itr != b_itr; ++itr) chmax(ans, a[i].second + itr->second);
      }
    }
    cout << ans << endl;
  }
  else if (*max_element(ALL(w)) <= 1000)
  {
    vector< vector<ll> > dp(n + 1, vector<ll>(1000 * n + 1, 0));
    rep(i, n) rep(wi, 1000 * n)
    {
      if (wi - w[i] >= 0) dp[i + 1][wi] = max(dp[i][wi - w[i]] + v[i], dp[i][wi]);
      else dp[i + 1][wi] = dp[i][wi];
    }
    cout << dp[n][min(1000 * n, weight)] << endl;
  }
  else
  {
    const ll INF = 1LL << 60;
    // dp[i][j] = i番目まで見て、価値がjの時の最小重さ
    vector< vector<ll> > dp(n + 1, vector<ll>(1000 * n + 1, INF));
    dp[0][0] = 0;
    rep(i, n) rep(j, 1000 * n)
    {
      if (j - v[i] >= 0) dp[i + 1][j] = min(dp[i][j - v[i]] + w[i], dp[i][j]);
      else dp[i + 1][j] = dp[i][j];
    }

    ll ans = 0;
    for(int i = 1000 * n; i >= 0; --i)
    {
      if (dp[n][i] <= weight)
      {
        ans = i;
        break;
      }
    }
    cout << ans << endl;
  }
  
}

int main()
{
  fastio;
  solve();

  return 0;
}