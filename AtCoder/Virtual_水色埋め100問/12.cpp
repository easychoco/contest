// https://atcoder.jp/contests/abc081/tasks/arc086_b
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
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
 
  int idx_max = 0, idx_min = 0;
  rep(i, n)
  {
    if (a[idx_max] <= a[i]) idx_max = i;
    if (a[idx_min] >= a[i]) idx_min = i;
  }

  vector<P> ans;
  if (a[idx_max] * a[idx_min] < 0)
  {
    if (abs(a[idx_max]) < abs(a[idx_min]))
    {
      rep(i, n)
      {
        a[i] += a[idx_min];
        ans.emplace_back(idx_min + 1, i + 1);
      }
    }
    else
    {
      rep(i, n)
      {
        a[i] += a[idx_max];
        ans.emplace_back(idx_max + 1, i + 1);
      }
    }
  }

  vector<ll> b(a);
  rep(i, n - 1) b[i + 1] += b[i];

  if (b[n - 1] < 0)
  {    
    for(int i = n - 1; i >= 1; --i)
    {
      a[i - 1] += a[i];
      ans.emplace_back(i + 1, i);
    }
  }
  else
  {
    rep(i, n - 1)
    {
      a[i + 1] += a[i];
      ans.emplace_back(i + 1, i + 2);
    }
  }

  cout << ans.size() << endl;
  for(const auto& p : ans)
  {
    cout << p.first << " " << p.second << endl;
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}