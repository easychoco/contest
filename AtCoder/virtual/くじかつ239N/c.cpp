// https://atcoder.jp/contests/agc013/tasks/agc013_a
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

  if (n == 1)
  {
    cout << "1\n";
    return;
  }

  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  a.erase(unique(ALL(a)), a.end());
  n = a.size();
  a.emplace_back(a.back());
  a.emplace_back(a.back());
  
  bool increase = (a[0] < a[1]);
  ll p = a[0];
  ll ans = 0;

  repi(i, 1, n + 1)
  {
    if (p < a[i] && !increase) { ans++; i++; }
    else if (p > a[i] && increase) { ans++; i++; }

    increase = (a[i - 1] < a[i]);
    p = a[i];
  }
  show(ans + 1);
}

int main()
{
  fastio;
  solve();

  return 0;
}