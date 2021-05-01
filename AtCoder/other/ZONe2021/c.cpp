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
  vector< vector<ll> > ins(5, vector<ll>(n));
  vector< vector<P> > inp(5, vector<P>(n));
  rep(i, n)
  {
    rep(j, 5) cin >> ins[j][i];
    rep(j, 5) inp[j][i] = P(ins[j][i], i);
  }

  rep(i, 5) sort(RALL(inp[i]));

  ll ans = 0;
  rep(i, n) repi(j, i + 1, n)
  {
    vector<ll> score(5);
    rep(k, 5) score[k] = max(ins[k][i], ins[k][j]);

    auto mins = min_element(ALL(score));
    ll idx = distance(score.begin(), mins);
    rep(ii, 3)
    {
      if (inp[idx][ii].second == i || inp[idx][ii].second == j) continue;
      chmax(*mins , inp[idx][ii].first);
    }
    chmax(ans, *min_element(ALL(score)));
  }
  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}