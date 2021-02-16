// https://atcoder.jp/contests/arc102/tasks/arc102_b
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
inline void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
inline void show(){ cout << endl; }
template <class Head, class... Tail>
inline void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }

void solve()
{
  ll l;
  cin >> l;

  ll node_num = 0;
  ll tmp = l;
  while(tmp > 0) {tmp >>= 1; node_num++; }

  ll cost = 1;
  ll now = 1;
  vector<tuple<ll, ll, ll>> ans;
  while(l > 1)
  {
    ans.emplace_back(now, now + 1, 0);
    ans.emplace_back(now, now + 1, cost);
    if (l & 1)
    {
      ans.emplace_back(now, node_num, (l - 1) * (1<<(now-1)));
    }
    l >>= 1;
    cost <<= 1;
    now++;
  }
  show(node_num, ans.size());
  for(auto t : ans)
  {
    ll from, to, cost;
    tie(from, to, cost) = t;
    show(from, to, cost);
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}