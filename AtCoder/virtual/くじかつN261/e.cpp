// https://atcoder.jp/contests/abc100/tasks/abc100_d
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
  ll n, m;
  cin >> n >> m;
  vector<tuple<ll, ll, ll>> t;
  rep(i, n)
  {
    ll x, y, z;
    cin >> x >> y >> z;
    t.emplace_back(x, y, z);
  }

  const ll sign[2] = { 1, -1 };
  ll ans = -1000000000000;
  for(ll sx: sign)
  for(ll sy: sign)
  for(ll sz: sign)
  {
    priority_queue<ll> que;
    rep(i, n)
    {
      ll x, y, z;
      tie(x, y, z) = t[i];
      que.push(x * sx + y * sy + z * sz);
    }
    ll score = 0;
    rep(i, m)
    {
      score += que.top();
      que.pop();
    }
    chmax(ans, score);
  }
  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}