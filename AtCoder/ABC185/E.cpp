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
  ll n, m;
  cin >> n >> m;
  vector<ll> a, b;
  if (n <= m)
  {
    a.resize(n);
    b.resize(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
  }
  else
  {
    b.resize(n);
    a.resize(m);
    rep(i, n) cin >> b[i];
    rep(i, m) cin >> a[i];
  }
  
  for(auto v : a) Show(v);
  Showln("");
  for(auto v : b) Show(v);
  Showln("");

  ll ai = a.size();
  ll bi = b.size();

  // サイズは a <= b なので、bからrm_num個取り除く
  ll rm_num = (bi - ai);
  
  vector<ll> dist(ai);
  rep(i, ai)
  {
    dist[i] = ai - i;
    repi(j, i, bi)
    {
      if (a[i] == b[j])
      {
        dist[i] = (j - i);
        break;
      }
    }
  }

  for(auto v : dist) Show(v);
  Showln("");

  const ll INF = 1LL << 62;
  vector<ll> dp(ai, INF);
  rep(i, ai)
  {
    auto itr = upper_bound(ALL(dp), dist[i]);
    if (itr != dp.end()) *itr = dist[i];
  }

  for(auto v : dist) Show(v);
  Showln("");
  for(auto v : dp) Show(v);
  Showln("");

  if (rm_num == 0)
  {
    ll ans = 0;
    rep(i, n) if (a[i] != b[i]) ans++;
    cout << ans<< endl;
    return;
  }

  ll d = distance(dp.begin(), lower_bound(ALL(dp), rm_num));
  cout << rm_num + (ai - d) << endl;

}

int main()
{
  fastio;
  solve();

  return 0;
}