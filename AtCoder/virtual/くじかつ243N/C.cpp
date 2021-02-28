// https://atcoder.jp/contests/keyence2019/tasks/keyence2019_c
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
void YN(bool a) { cout << (a ? "Yes" : "No"); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }

void solve()
{
  ll n;
  cin >> n;
  vector<ll> a(n), b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];

  vector<ll> po, ne;
  ll asum = 0;
  ll bsum = 0;
  rep(i, n)
  {
    if (a[i] < b[i]) ne.emplace_back(b[i] - a[i]);
    if (a[i] > b[i]) po.emplace_back(a[i] - b[i]);
    asum += a[i];
    bsum += b[i];
  }
  if (asum < bsum)
  {
    show(-1);
    return;
  }

  sort(RALL(po));
  ll ta = accumulate(ALL(ne), 0LL);
  ll sum = 0;
  ll ans = 0;
  while(sum < ta)
  {
    sum += po[ans];
    ans++;
  }
  ans += ne.size();
  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}