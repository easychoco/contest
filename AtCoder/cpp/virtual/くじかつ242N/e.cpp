// https://atcoder.jp/contests/dwacon5th-prelims/tasks/dwacon5th_prelims_b
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
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n)
  {
    cin >> a[i];
  }

  vector<ll> pool;
  rep(i, n)
  {
    rep(j, i + 1)
    {
      ll sum = 0;
      repi(ki, j, i + 1) sum += a[ki];  
      pool.emplace_back(sum);
    }
  }


  ll ans = 0;
  for(ll bit = 40; bit >= 0; --bit)
  {
    vector<ll> next;
    rep(i, pool.size())
    {
      if (pool[i] & (1LL<<bit))
      {
        next.emplace_back(pool[i]);
      }
    }
    if (next.size() >= k)
    {
      ans += (1LL<<bit);
      pool.resize(next.size());
      pool = next;
    }
  }
  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}