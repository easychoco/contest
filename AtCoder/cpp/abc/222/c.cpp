#include <bits/stdc++.h>
#include <atcoder/all>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=(a);i<(ll)(n);++i)
#define repe(i,n) repie(i,0,n)
#define repie(i,a,n) for(ll i=(a);i<=(ll)(n);++i)
#define rrep(i,n) rrepi(i,n,0)
#define rrepi(i,n,a) for(ll i=(n);i>=(a);--i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using namespace atcoder;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using P = pair<ll, ll>;
const ll INF = 1LL << 60;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }

ll win(char p1, char p2)
{
  if (p1 == p2) return 0;
  if (p1 == 'G' && p2 == 'C') return 1;
  if (p1 == 'G' && p2 == 'P') return 2;
  if (p1 == 'C' && p2 == 'G') return 2;
  if (p1 == 'C' && p2 == 'P') return 1;
  if (p1 == 'P' && p2 == 'G') return 1;
  if (p1 == 'P' && p2 == 'C') return 2;
  return -10;
}

void solve()
{
  ll n, m;
  cin >> n >> m;
  vector<string> a(2 * n);
  rep(i, n * 2)
  {
    cin >> a[i];
  }

  vector<P> num(2 * n, P(0, 0));
  rep(i, 2 * n) num[i].second = -i;

  rep(i, m)
  {
    rep(j, n)
    {
      char p1 = a[-num[(j * 2)].second][i];
      char p2 = a[-num[(j * 2 + 1)].second][i];
      ll res = win(p1, p2);
      if (res == 1) num[(j * 2)].first++;
      if (res == 2) num[(j * 2 + 1)].first++;
    }
    sort(RALL(num));
  }
  rep(i, 2 * n) show(-num[i].second + 1);
}

int main()
{
  fastio;
  solve();

  return 0;
}
