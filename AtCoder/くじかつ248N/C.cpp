// https://atcoder.jp/contests/arc098/tasks/arc098_a
#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=a;i<(ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
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
  string s;
  cin >> n >> s;

  vector<ll> hist(n, 0), b(n, 0);
  rep(i, n) hist[i] = ((s[i] == 'W') ? 0 : 1);
  // W が左, 0が左

  b[0] = hist[0];
  repi(i, 1, n) b[i] = b[i - 1] + hist[i];

  ll ans = n * 2;
  rep(i, n)
  {
    ll le = 0, re = 0;
    if (i > 0) le = i - b[i - 1];
    re = b[n - 1] - b[i];
    // show(i, le, re);
    chmin(ans, le + re);
  }
  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}