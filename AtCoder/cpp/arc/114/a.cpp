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

// 最大公約数 : 3,4 ->  1
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

void solve()
{
  ll n;
  cin >> n;
  vector<ll> x(n);
  rep(i, n)
  {
    cin >> x[i];
  }

  ll prime[15] = {
    2,
    3,
    5,
    7,
    11,
    13,
    17,
    19,
    23,
    29,
    31,
    37,
    41,
    43,
    47,
  };

  vector<ll> anss;
  repi(mask, 1, 1LL << 15)
  {
    ll pro = 1;
    rep(i, 15) if (mask & (1LL << i)) pro *= prime[i];
    anss.emplace_back(pro);
  }

  sort(ALL(anss));
  for(auto p : anss)
  {
    bool ok = true;
    rep(i, n)
    {
      if (gcd(p, x[i]) == 1)
      {
        ok = false;
        break;
      }
    }
    if (ok)
    {
      show(p);
      return;
    }
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}