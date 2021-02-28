// https://atcoder.jp/contests/arc068/tasks/arc068_b
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
  ll n;
  cin >> n;
  vector<ll> hist(100010, 0);
  rep(i, n)
  {
    ll a;
    cin >> a;
    hist[a]++;
  }

  ll ans = 0;
  deque<ll> deq;
  rep(i, 100010)
  {
    if (hist[i] > 0)
    {
      hist[i]--;
      ans++;
      if (hist[i] > 0) deq.emplace_back(hist[i]);
    }
  }

  while(deq.size() >= 2)
  {
    ll f = deq.front();
    ll b = deq.back();
    deq.pop_front();
    deq.pop_back();
    if (f < b) deq.emplace_back(b - f);
    if (b < f) deq.emplace_front(f - b);
    // b == f はpopしたまま
  }
  if (!deq.empty())
  {
    ans -= deq.front() % 2;
  }
  show(max(1LL, ans));
}

int main()
{
  fastio;
  solve();

  return 0;
}