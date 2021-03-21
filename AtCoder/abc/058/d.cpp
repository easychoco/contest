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

using mint = modint1000000007;

void solve()
{
  ll n, m;
  cin >> n >> m;
  vector<ll> x(n);
  vector<ll> y(m);
  
  rep(i, n) cin >> x[i];
  rep(i, m) cin >> y[i];


  mint sumx = x[1] - x[0];
  mint px = sumx;
  repi(i, 2, n)
  {
    mint rx = x[i] - x[i - 1];
    sumx += px + i * rx;
    px += i * rx;
  }

  mint sumy = y[1] - y[0];
  mint py = sumy;
  repi(i, 2, m)
  {
    mint ry = y[i] - y[i - 1];
    sumy += py + i * ry;
    py += i * ry;
  }

  show((sumx * sumy).val());
}

int main()
{
  fastio;
  solve();

  return 0;
}
