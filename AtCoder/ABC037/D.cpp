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

ll dp[1000][1000];
ll a[1000][1000];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void solve()
{
  int h, w;
  cin >> h >> w;
  vector<tuple<ll, ll, ll>> nums;
  rep(y, h) rep(x, w)
  {
    cin >> a[y][x];
    nums.emplace_back(a[y][x], y, x);
  }
  sort(ALL(nums));
  rep(y, h) rep(x, w) dp[y][x] = 1;

  // dp[y][x] = マス(y, x)で経路を終えるものの個数
  rep(ai, h * w)
  {
    int num, y, x;
    tie(num, y, x) = nums[ai];
    rep(i, 4)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (0 <= nx && nx < w && 0 <= ny && ny < h && num < a[ny][nx])
      {
        dp[ny][nx] += dp[y][x];
        dp[ny][nx] %= 1000000007;
      }
    }
  }
  
  ll ans = 0;
  rep(y, h) rep(x, w)
  {
    ans += dp[y][x];
    ans %= 1000000007;
  }
  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}