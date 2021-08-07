// https://atcoder.jp/contests/abc178/tasks/abc178_f
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
  vector<ll> a(n), b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];

  vector<ll> ha(n + 1, 0), hb(n + 1, 0);
  rep(i, n) ha[a[i]]++;
  rep(i, n) hb[b[i]]++;

  rep(i, n + 1)
  {
    if (ha[i] + hb[i] > n)
    {
      cout << "No\n";
      return;
    }
  }

  cout << "Yes\n";

  const ll INF = 1LL << 60;
  vector<ll> fa(n + 1, INF);
  vector<ll> bb(n + 1, 0);
  rep(i, n) chmin(fa[a[i]], i);
  rep(i, n) chmax(bb[b[i]], i);

  ll d = 0;
  rep(i, n + 1) chmax(d, bb[i] - fa[i] + 1);
  rep(i, n) Show(b[(i + d) % n]);
}

int main()
{
  fastio;
  solve();

  return 0;
}