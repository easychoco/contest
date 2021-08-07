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

#define TA first
#define TC second

#define C first
#define A second

// 最大公約数 : 3,4 ->  1
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

void solve()
{
  ll n, m;
  cin >> n >> m;
  vector<P> tq(m);
  rep(i, m)
  {
    ll a, c;
    cin >> a >> c;
    tq[i] = make_pair(a, c);
  }

  sort(ALL(tq));

  vector<P> q;
  q.emplace_back(tq[0].TC, tq[0].TA);
  repi(i, 1, m)
  {
    if (tq[i].TA != tq[i - 1].TA) q.emplace_back(tq[i].TC, tq[i].TA);
  }

  sort(ALL(q));
  ll gd = n;
  ll sz = q.size();
  ll ans = 0;

  rep(i, sz)
  {
    ll pgd = gd;
    gd = gcd(gd, q[i].A);
    ans += q[i].C * (pgd - gd);
    if (gd == 1)
    {
      show(ans);
      return;
    }
  }
  show(-1);
}

int main()
{
  fastio;
  solve();

  return 0;
}