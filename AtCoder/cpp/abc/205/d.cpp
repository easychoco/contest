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

void solve()
{
  ll n, q;
  cin >> n >> q;
  vector<ll> a(n), b(n);
  map<ll, ll> mp;
  rep(i, n)
  {
    cin >> a[i];
  }

  b.back() = a.back() + 1;
  for(ll i = n - 2; i >= 0; --i)
  {
    if (a[i] + 1 == a[i + 1]) b[i] = b[i + 1];
    else b[i] = a[i] + 1;
  }

  mp[0] = 0;
  ll sum = b[0] - a[0];
  mp[a[0]] = sum;
  repi(i, 1, n)
  {
    if (b[i - 1] != b[i])
    {
      mp[a[i] - sum] = sum + b[i] - a[i];
      sum += b[i] - a[i];
    }
  }
  
  rep(_,  q)
  {
    ll k;
    cin >> k;

    auto itr = mp.upper_bound(k);
    itr--;
    show(k + itr->second);
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}