#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;

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
	int n, q;
  cin >> n >> q;

  BIT<ll> bit(n * 2);

  int c, x, y;
  for(int i = 0; i < q; ++i)
  {
    cin >> c >> x >> y;
    if (c == 0)
    {
      bit.add(x, y);
    }
    else
    {
      cout << bit.sum(x, y + 1) << endl;
    }
  }
}

int main()
{
	fastio;
	solve();

	return 0;
}