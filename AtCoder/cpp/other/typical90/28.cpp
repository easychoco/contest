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

  ll h = 1010, w = 1010;
  vector<vector<ll>> a(h, vector<ll>(w, 0));
  rep(i, n)
  {
    ll lx, ly, rx, ry;
    cin >> lx >> ly >> rx >> ry;
    a[ly][lx] += 1;
    a[ry][lx] += -1;
    a[ly][rx] += -1;
    a[ry][rx] += 1;
  }

  vector<vector<ll>> sum(h + 1, vector<ll>(w + 1, 0));
  rep(y, h) rep(x, w) sum[y + 1][x + 1] = sum[y][x + 1] + sum[y + 1][x] - sum[y][x] + (a[y][x]);

  vector<ll> ans(n + 1, 0);
  rep(y, h) rep(x, w)
  {
    ans[sum[y][x]]++;
  }
  repie(i, 1, n) show(ans[i]);
}

int main()
{
  fastio;
  solve();

  return 0;
}