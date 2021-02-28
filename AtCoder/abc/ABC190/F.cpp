#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=a;i<(ll)n;++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define Show(val) cout<<(val)<<" "
#define Showln(val) cout<<(val)<<endl

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// using P = pair<int, int>;
void YN(bool a) { cout << (a ? "Yes" : "No"); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

// BIT
// Binary Indexed Tree
// https://scrapbox.io/pocala-kyopro/%E8%BB%A2%E5%80%92%E6%95%B0
// 1-index
struct BIT {
private:
  vector<int> bit;
  int N;

public:
  BIT(int size) {
    N = size;
    bit.resize(N + 1);
  }

  // 一点更新
  void add(int a, int w) {
    for (int x = a; x <= N; x += x & -x) bit[x] += w;
  }

  // 1~Nまでの和を求める。
  int sum(int a) {
    int ret = 0;
    for (int x = a; x > 0; x -= x & -x) ret += bit[x];
    return ret;
  }
};

void solve()
{
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n)
  {
    cin >> a[i];
    a[i]++;
  }

  ll num = 0;
  BIT bit(n);
  rep(i, n)
  {
    num += i - bit.sum(a[i]);
    bit.add(a[i], 1);
  }
  rep(i, n)
  {
    Showln(num);
    num += n + 1 - a[i] * 2;
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}