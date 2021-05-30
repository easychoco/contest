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

ll min_diff(vector<ll> &a, vector<ll> &b)
{
  ll ai = 0, bi = 0;
  ll sza = a.size();
  ll szb = b.size();
  ll ret = 1LL << 60;

  while (ai < sza && bi < szb)
  {
    chmin(ret, abs(a[ai] - b[bi]));
    if (ai < sza - 1 && a[ai] < b[bi]) ai++;
    else bi++;
  }
  return ret;
}

void solve()
{
  ll n;
  cin >> n;

  vector<ll> r;
  vector<ll> g;
  vector<ll> b;
  rep(i, 2 * n)
  {
    ll a;
    char c;
    cin >> a >> c;
    if (c == 'R') r.emplace_back(a);
    if (c == 'G') g.emplace_back(a);
    if (c == 'B') b.emplace_back(a);
  }

  if ((ll)r.size() % 2 == 0 && (ll)g.size() % 2 ==  0 && (ll)b.size() % 2 == 0)
  {
    show(0);
    return;
  }

  sort(ALL(r));
  sort(ALL(g));
  sort(ALL(b));

  vector<ll> even, odd1, odd2;
  if ((ll)r.size() % 2 == 0)
  {
    even = r;
    odd1 = g;
    odd2 = b;
  }
  if ((ll)g.size() % 2 == 0)
  {
    odd1 = r;
    even = g;
    odd2 = b;
  }
  if ((ll)b.size() % 2 == 0)
  {
    odd1 = r;
    odd2 = g;
    even = b;
  }

  show( min(min_diff(odd1, odd2), min_diff(even, odd1) + min_diff(even, odd2)) );
}

int main()
{
  fastio;
  solve();

  return 0;
}