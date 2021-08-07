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
  vector< vector<ll> > ins(n, vector<ll>(5));
  rep(i, n)
  {
    rep(j, 5) cin >> ins[i][j];
  }

  auto f = [&](ll arg)
  {
    set<ll> st;
    rep(i, n)
    {
      ll score = 0;
      rep(bit, 5) if (ins[i][bit] >= arg) score |= (1 << bit);
      st.insert(score);
    }
    for(auto x : st) for(auto y : st) for(auto z : st)
    {
      if ((x | y | z) == 31) return true;
    }
    return false;
  };

  ll ac = 0, wa = 1000000001LL;
  while(wa - ac > 1)
  {
    ll wj = (ac + wa) / 2;
    if ( f(wj) ) ac = wj;
    else wa = wj;
  }
  show(ac);
}

int main()
{
  fastio;
  solve();

  return 0;
}