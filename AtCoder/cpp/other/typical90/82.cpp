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

using mint = modint1000000007;

mint calc(mint st, mint de)
{
  return (de - st + 1) * (st + de) * mint(2).inv();
}

void solve()
{
  ll l, r;
  cin >> l >> r;

  ll digit = 1;
  ll cnt = 1;
  mint ans = 0;
  while(digit <= l / 10)
  {
    digit *= 10;
    cnt++;
  }

  ans += calc(l, digit - 1) * cnt;
  while(true)
  {
    if (digit <= r / 10)
    {
      mint st = digit;
      mint de = digit;
      de *= 10;
      de -= 1;
      ans += calc(st, de) * cnt;
    }
    else
    {
      ans += calc(digit, r) * cnt;
      break;
    }
    digit *= 10;
    cnt++;
  }
  show(ans.val());
}

int main()
{
  fastio;
  solve();

  return 0;
}