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

ll getnum(ll pow)
{ // 入力を文字列で受け取って、10^pow 倍して返す。小数の丸め誤差対策。
  string in;
  cin >> in;
  for(int i = 0; i < pow; ++i) in += '0';
  for(int i = 1; i < (int)in.length(); ++i)
  {
    if (in[i] == '.')
    {
      swap(in[i], in[i + 1]);
      pow--;
      if (pow <= 0) break;
    }
  }
  ll ret = stol(in);
  return ret;
}

void solve()
{
  ll n = getnum(5);
  ll ans = 0;

  repie(i, 1, n / 100000)
  {
    ans += n / i;
  }
  printf("%.5lf\n", (ans / 100000.0) - 1.0);
}

int main()
{
  fastio;
  solve();

  return 0;
}