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
  vector<tuple<ll, ll>> input(n);
  rep(i, n)
  {
    ll x, y, r;
    cin >> x >> y >> r;
    input[i] = make_tuple(y, i);
  }

  sort(ALL(input));

  vector<tuple<ll, ll, ll, ll>> ans(n);
  ll py;
  {
    ll y, ii;
    tie(y, ii) = input[0];

    y++;
    ans[ii] = make_tuple(0, 0, 10000, y);
    py = y;
  }

  repi(i, 1, n - 1)
  {
    ll yy, ii;
    tie(yy, ii) = input[i];

    ll y = yy + 1;
    if (y <= py) y = py + 1;
    chmin(y, 10000LL);
    ans[ii] = make_tuple(0, py, 10000, y);
    py = y;
  }

  {
    ll y, ii;
    tie(y, ii) = input[n - 1];

    y++;
    ans[ii] = make_tuple(0, py, 10000, 10000);
    py = y;
  }
  
  rep(i, n)
  {
    ll a, b, c, d;
    tie(a, b, c, d) = ans[i];
    show(a, b, c, d);
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}