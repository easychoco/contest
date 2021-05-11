// https://atcoder.jp/contests/arc062/tasks/arc062_b
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
  string s;
  cin >> s;

  ll ans = 0;
  ll gn = 1, pn = 0;
  repi(i, 1, s.length())
  {
    if (s[i] == 'g')
    {
      if (pn < gn) { pn++; ans++; }
      else gn++;
    }
    if (s[i] == 'p')
    {
      if (pn < gn) { pn++; }
      else { gn++; ans--; }
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