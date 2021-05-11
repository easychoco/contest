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

ll ans = 0;
int n, m, q, ai, bi, ci, di;
vector<tuple<int, int, int, int>> abcd;
void dfs(vector<int>& seq)
{
  if (seq.size() >= n)
  {
    ll score = 0;
    rep(i, q)
    {
      int a, b, c, d;
      tie(a, b, c, d) = abcd[i];
      if (seq[b] - seq[a] == c) score += d;
    }
    chmax(ans, score);
    return;
  }

  for(int i = seq.back(); i <= m; ++i)
  {
    vector<int> next(seq);
    next.emplace_back(i);
    dfs(next);
  }
}

void solve()
{
  cin >> n >> m >> q;
  rep(i, q)
  {
    cin >> ai >> bi >> ci >> di;
    abcd.emplace_back(ai - 1, bi - 1, ci, di);
  }

  for(int i = 1; i <= m; ++i)
  {
    vector<int> next{i};
    dfs(next);
  }

  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}