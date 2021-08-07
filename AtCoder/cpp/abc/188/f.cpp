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

ll x, y;
unordered_map<ll, ll> mp;

// y を x にする
ll rec(ll val)
{
  if (mp[val] > 0) return mp[val];
  if (val <= x) return mp[val] = x - val;

  ll ret = 1LL << 60;

  if (val & 1) // 奇数なら
  {
    ret = min({ abs(val - x), 2 + rec((val - 1) / 2), 2 + rec((val + 1) / 2) });
  }
  else // if (偶数なら)
  {
    ret = min({ abs(val - x), 1 + rec(val / 2) });
  }
  return mp[val] = ret;
}

void solve()
{
  cin >> x >> y;
  show(rec(y));
}

int main()
{
  fastio;
  solve();

  return 0;
}