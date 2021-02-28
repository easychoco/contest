// https://atcoder.jp/contests/abc141/tasks/abc141_d
#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=a;i<(ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
void YN(bool a) { cout << (a ? "Yes" : "No"); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }

void solve()
{
  ll n, m;
  cin >> n >> m;
  priority_queue<ll> que;
  rep(i, n)
  {
    ll a;
    cin >> a;
    que.push(a);
  }

  rep(i, m)
  {
    ll a = que.top();
    que.pop();
    que.push(a / 2);
  }
  
  ll ans = 0;
  while(!que.empty())
  {
    ans += que.top();
    que.pop();
  }
  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}