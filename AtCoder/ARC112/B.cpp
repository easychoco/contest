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
  ll b, c;
  cin >> b >> c;

  ll vmin = 0;
  ll vmax = 0;

  ll ans = 0;
  if (b == 0)
  {
    vmin = -(c / 2);
    vmax = (c - 1) / 2;
    ans = vmax - vmin + 1;
  }
  else if (b < 0)
  {
    vmin = b - c / 2;
    vmax = -b + (c - 1) / 2;
    if (-b > (c - 1) / 2) // 0 をまたがない
    {
      ans = vmax - (-b - (c - 1) / 2) + 1;
      ans += -(-b - (c - 2) / 2) - vmin + 1;
    } else {
      ans = vmax - vmin + 1;      
    }
  }
  else
  {
    vmax = b + (c - 2) / 2;
    vmin = -b - (c - 1) / 2;
    if (b > c / 2) // 0 をまたがない
    {
      ans = vmax - (b - c / 2) + 1;
      ans += -(b - (c - 1) / 2) - vmin + 1;
    } else {
      ans = vmax - vmin + 1;
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