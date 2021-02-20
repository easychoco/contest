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
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }

void solve()
{
  string x;
  ll mi;
  cin >> x >> mi;

  __int128 m = mi;
  if (x.length() == 1)
  {
    if (m < stoi(x))
    {
      show(0);
    }
    else
    {
      show(1);
    }
    return;
  }

  ll d = (ll)(*max_element(ALL(x)) - '0') + 1;
  reverse(ALL(x));

  auto f = [&](__int128 dd)
  {
    __int128 num = 0;
    __int128 base = 1;
    rep(i, x.length())
    {
      num += base * (ll)(x[i] - '0');
      base *= dd;
      if (num > m || base > dd * m) return false;
    }
    return true;
  };

  ll ac = d, wa = m + 1LL;
  while(wa - ac > 1)
  {
    ll wj = (ac + wa) / 2;
    if ( f(wj) ) ac = wj;
    else wa = wj;
  }

  if (!f(ac)) d++;
  show(ac - d + 1);
}

int main()
{
  fastio;
  solve();

  return 0;
}