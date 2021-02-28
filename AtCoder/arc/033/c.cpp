#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i = a;i < (ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define SHOW(str,val) cout<<(str)<<" : "<<(val)<<endl;

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// using P = pair<int, int>;
void YN(bool a) { cout << (a ? "Yes" : "No"); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true;} return false;}

// Binary Indexed Tree (Fenwick Tree)
// https://youtu.be/lyHk98daDJo?t=7960
template<typename T>
struct BIT {
  int n;
  vector<T> d;
  BIT(int n=0):n(n),d(n+1) {}
  void add(int i, T x=1) {
    for (i++; i <= n; i += i&-i) {
      d[i] += x;
    }
  }
  T sum(int i) {
    T x = 0;
    for (i++; i; i -= i&-i) {
      x += d[i];
    }
    return x;
  }
  T sum(int l, int r) {
    return sum(r-1) - sum(l-1);
  }
};

void solve()
{
  int q, t, x;
  cin >> q;
  BIT<int> bit(200010);
  auto f = [&](ll arg){ return bit.sum(arg); };

  rep(i, q)
  {
    cin >> t >> x;
    if (t == 1)
    {
      bit.add(x, 1);
    }
    if (t == 2)
    {
      ll le = 0, re = 200009LL;
      while(re - le > 1)
      {
        ll mid = (le + re) / 2;
        if ( x <= f(mid) ) re = mid;
        else le = mid;
      }
      cout << re << endl;
      bit.add(re, -1);
    }
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}