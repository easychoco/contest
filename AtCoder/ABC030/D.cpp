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
  ll n, a;
  string k;
  cin >> n >> a >> k;
  a--;
  vector<ll> b(n);
  rep(i, n)
  {
    cin >> b[i];
    b[i]--;
  }

  if (k.length() <= 7)
  {
    ll kk = stoll(k);
    ll now = a;
    rep(i, kk) now = b[now];
    Showln(now + 1);
    return;
  }

  vector<ll> loop(n, -1);
  ll now = a;
  ll cnt = 0;
  while(true)
  {
    if (loop[now] != -1) break;
    loop[now] = cnt;
    now = b[now];
    cnt++;
  }
  ll before_cycle = loop[now];
  ll loop_cycle = cnt - loop[now];

  ll kk = 0;
  rep(i, k.length())
  {
    kk = kk * 10 + (k[i] - '0');
    kk %= loop_cycle;
  }
  while(kk < before_cycle) kk += loop_cycle;
  kk -= before_cycle;
  kk %= loop_cycle;

  rep(i, kk) now = b[now];
  Showln(now + 1);
}

int main()
{
  fastio;
  solve();

  return 0;
}