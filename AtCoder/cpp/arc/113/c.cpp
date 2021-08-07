#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=a;i<(ll)n;++i)
#define repie(i,a,n) for(ll i=a;i<=(ll)n;++i)
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

  ll sz = s.length();
  string ss = string(sz, '-');
  char now = '-';
  repi(i, 2, sz)
  {
    if (s[i - 2] == s[i - 1] && s[i - 1] != s[i] && s[i - 1] != now)
    {
      ss[i] = s[i - 1];
      now = ss[i];
    }
  }
  
  reverse(ALL(s));
  reverse(ALL(ss));

  now = '-';
  ll ans = 0;
  ll le = 0;
  rep(i, sz)
  {
    if (ss[i] != '-')
    {
      ans += i + 1;
      now = ss[i];
      repie(j, le, i) if (s[j] == now) ans--;
      i += 1;
      le = i;
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