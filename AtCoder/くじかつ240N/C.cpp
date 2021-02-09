// https://atcoder.jp/contests/agc039/tasks/agc039_a
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
void YN(bool a) { cout << (a ? "Yes" : "No"); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }

void solve()
{
  string s, os;
  ll k;
  cin >> os >> k;

  s = os;
  set<char> st;
  rep(i, s.length()) st.insert(s[i]);
  if (st.size() == 1)
  {
    show(s.length() * k / 2LL);
    return;
  }

  bool same = (s[0] == s.back());
  ll sz = s.length();
  repi(i, 1, sz)
  {
    if (s[i - 1] != s[i])
    {
      s += s.substr(0, i);
      s = s.substr(i, sz);
      break;
    }
  }

  // show(s);

  ll len = 1;
  ll cnt = 0;
  repi(i, 1, s.length())
  {
    if (s[i - 1] == s[i])
    {
      len++;
    }
    else
    {
      if (len > 1) cnt += len / 2;
      len = 1;
    }
    
  }
  cnt += len / 2;

  ll ans = cnt * k;

  if (same)
  {
    ll f = 0;
    ll b = 0;
    rep(i, sz)
    {
      if (os[i] == os[0]) f++;
      else break;
    }
    for(ll i = sz - 1; i >= 0; --i)
    {
      if (os[i] == os.back()) b++;
      else break;
    }
    ans -= (f + b) / 2;
    ans += f / 2 + b / 2;
  }

  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}