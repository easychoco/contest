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
  ll a, b, w;
  cin >> a >> b >> w;
  w *= 1000;

  ll ansmin = 1LL << 60;
  ll ansmax = -10;

  rep(i, 1000010)
  if (a * i <= w && w <= b * i)
  {
    if (w % a == 0) ansmax = w / a;
    else ansmax = w / a;
    if (w % b == 0) ansmin = w / b;
    else ansmin = w / b + 1;

    show(ansmin, ansmax);
    return;
  }

  show("UNSATISFIABLE");
}

int main()
{
  fastio;
  solve();

  return 0;
}