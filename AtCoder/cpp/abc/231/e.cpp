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
using ll = int_fast64_t;
using vl = vector<ll>;
using vvl = vector<vl>;
using P = pair<ll, ll>;
using vp = vector<P>;
using vvp = vector<vp>;
const ll INF = 1LL << 60;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }

ll calc(vl &yen, ll price)
{
  ll ret = 0;
  ll now = 0;
  while (price > 0)
  {
    ret += price / yen[now];
    price %= yen[now];
    now++;
  }
  return ret;
}

void solve()
{
  ll n, x;
  cin >> n >> x;
  vl yen(n);
  rep(i, n) cin >> yen[i];

  sort(ALL(yen));
  ll big_idx = n - 1;
  rep(i, n)
  {
    if (yen[i] >= x)
    {
      big_idx = i;
      break;
    }
  }
  yen.erase(yen.begin() + big_idx + 1, yen.end());
  reverse(ALL(yen));
  ll sz = yen.size();

  ll ans = calc(yen, x);

  vl price;
  ll base = yen[0] * ((x - 1) / yen[0] + 1);
  price.push_back(base);
  rep(i, sz)
  {
        
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}
