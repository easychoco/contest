#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i = a;i < (ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define Show(val) cout<<(val)<<endl;
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
  int n, w, inw, inv;
  cin >> n >> w >> inw >> inv;
  vector<vector<int>> b(4, vector<int>());

  b[0].emplace_back(inv);
  ll base_w = inw;
  repi(i, 1, n)
  {
    cin >> inw >> inv;
    b[inw - base_w].emplace_back(inv);
  }

  ll ans = 0;

  sort(RALL(b[0]));
  sort(RALL(b[1]));
  sort(RALL(b[2]));
  sort(RALL(b[3]));

  rep(i0, b[0].size() + 1)
  rep(i1, b[1].size() + 1)
  rep(i2, b[2].size() + 1)
  rep(i3, b[3].size() + 1)
  {
    ll sum_w = 0;
    sum_w += base_w * i0;
    sum_w += (base_w + 1) * i1;
    sum_w += (base_w + 2) * i2;
    sum_w += (base_w + 3) * i3;
    if (sum_w > w) break;

    ll sum_v = 0;
    sum_v += accumulate(b[0].begin(), b[0].begin() + i0, 0LL);
    sum_v += accumulate(b[1].begin(), b[1].begin() + i1, 0LL);
    sum_v += accumulate(b[2].begin(), b[2].begin() + i2, 0LL);
    sum_v += accumulate(b[3].begin(), b[3].begin() + i3, 0LL);
    chmax(ans, sum_v);
  }

  cout << ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}