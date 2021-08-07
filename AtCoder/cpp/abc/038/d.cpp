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
  ll n, wi, hi;
  cin >> n;
  vector<P> wh(n);
  rep(i, n)
  {
    cin >> wi >> hi;
    wh[i] = P(wi, hi);
  }

  // dp[i] = 増加部分列の長さがiの時の部分列の末尾にくる最小数
  const ll INF = 1LL << 60;
  vector<ll> dp(n + 3, INF);

  sort(ALL(wh));
  dp[0] = 0;

  rep(i, n)
  {
    vector<P> update_pos;

    auto p_itr = lower_bound(ALL(dp), wh[i].second);
    update_pos.emplace_back(P(distance(dp.begin(), p_itr), wh[i].second));

    while(i + 1 < n && wh[i].first == wh[i + 1].first)
    {
      i++;
      auto n_itr = lower_bound(ALL(dp), wh[i].second);
      ll idx = distance(dp.begin(), n_itr);
      if (update_pos.back().first != idx)
      {
        update_pos.emplace_back(P(idx, wh[i].second));
      }
    }

    rep(j, update_pos.size())
    {
      dp[update_pos[j].first] = update_pos[j].second;
    }
  }

  auto itr = lower_bound(ALL(dp), INF);
  cout << distance(dp.begin(), itr) - 1 << endl;
}

int main()
{
  fastio;
  solve();

  return 0;
}