// https://atcoder.jp/contests/abc154/tasks/abc154_d
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
  ll n, k;
  cin >> n >> k;
  vector<ll> p(n);
  rep(i, n)
  {
    cin >> p[i];
    p[i]++;
  }

  ll sum = accumulate(p.begin(), p.begin() + k, 0LL);

  double ans = sum / 2.0;
  repi(i, k, n)
  {
    sum += p[i];
    sum -= p[i - k];
    chmax(ans, sum / 2.0);
  }
  printf("%.7lf\n", ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}