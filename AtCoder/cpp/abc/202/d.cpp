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


/*--- 異なるn個からr個の整数を取り出す組み合わせの数を返す ---*/
ll comb[65][65];
ll combination(int n, int r)
{
  if (comb[n][r] > 0) return comb[n][r];
  if (r == 0 || r == n)
    return comb[n][r] = (1);
  else if (r == 1)
    return comb[n][r] = (n);
  return comb[n][r] = (combination(n - 1, r - 1) + combination(n - 1, r));
}

void solve()
{
  ll a, b, k;
  cin >> a >> b >> k;

  ll rest_a = a, rest_b = b;
  ll rank = 0;
  string ans = "";
  // 0011 0101 0110 1001 1010 1100
  //    3    5    6    9   10   12
  rep(i, a + b)
  {
    // i 文字目が a か b かを決める
    // tmp は b にしたときの順位
    ll tmp = rank + combination(rest_a + rest_b - 1, rest_b);
    // show("rank", rank, ": a", rest_a, 'b', rest_b, "/ tmp", tmp);
    if (k < tmp + 1)
    {
      ans += 'a';
      rest_a--;
    }
    else
    {
      rank = tmp;
      ans += 'b';
      rest_b--;
    }

    if (rest_a <= 0 || rest_b <= 0) break;
  }
  rep(i, rest_a) ans += 'a';
  rep(i, rest_b) ans += 'b';
  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}