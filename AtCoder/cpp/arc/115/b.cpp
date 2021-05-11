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
  vector< vector<ll> > c(n, vector<ll>(n));
  rep(y, n)
  rep(x, n)
  {
    cin >> c[y][x];
  }

  ll minv = 1LL << 60;
  vector<ll> diff(n, 0);
  rep(x, n)
  {
    diff[x] = c[0][x] - c[0][0];
    chmin(minv, diff[x]);
  }

  rep(y, n)
  {
    bool ok = true;
    rep(x, n)
    {
      ok &= (c[y][x] - c[y][0] == diff[x]);
    }
    if (!ok)
    {
      YN(false);
      return;
    }
  }

  vector<ll> ans_a(n);
  vector<ll> ans_b(n);
  YN(true);
  rep(i, n) ans_b[i] = diff[i] - minv;
  rep(i, n) ans_a[i] = c[i][0] + minv;

  showall(ans_a);
  showall(ans_b);
}

int main()
{
  fastio;
  solve();

  return 0;
}