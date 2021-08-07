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
  vector<ll> sum1(n + 1, 0), sum2(n + 1, 0);
  rep(i, n)
  {
    ll c, p;
    cin >> c >> p;
    if (c == 1) sum1[i + 1] = p;
    if (c == 2) sum2[i + 1] = p;
  }

  rep(i, n)
  {
    sum1[i + 1] += sum1[i];
    sum2[i + 1] += sum2[i];
  }

  ll q;
  cin >> q;
  rep(_, q)
  {
    ll l, r;
    cin >> l >> r;
    show(sum1[r] - sum1[l - 1], sum2[r] - sum2[l - 1]);
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}