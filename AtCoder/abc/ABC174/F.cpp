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

int ans[500010];

void solve()
{
  int n, q, c, l, r;
  cin >> n >> q;
  BIT<int> bit(n + 1);

  // tuple<left, right, isNum, idx>
  vector<tuple<int, int, int, int>> range;
  vector<int> pos(500001, -1);
  rep(i, n)
  {
    cin >> c;
    if (pos[c] != -1) range.emplace_back(pos[c], -i, 1, 505050);
    pos[c] = i;
  }

  rep(i, q)
  {
    cin >> l >> r;
    range.emplace_back(l - 1, - r + 1, 0, i);
  }

  // 第1要素は降順、第2要素は昇順
  // どちらも同値ならqueryのほうが後に来るようにする
  sort(RALL(range));

  ll le, re, isNum, idx;
  for(const auto& v : range)
  {
    tie(le, re, isNum, idx) = v;
    re = -re;
    if (isNum)
    {
      bit.add(re + 1);
    }
    else
    {
      int s = bit.sum(re + 1);
      ans[idx] = re - le - s + 1;
    }
  }
  
  rep(i, q) Showln(ans[i]);
}

int main()
{
  fastio;
  solve();

  return 0;
}