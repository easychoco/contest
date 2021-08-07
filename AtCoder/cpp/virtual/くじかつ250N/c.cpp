// https://atcoder.jp/contests/abc181/tasks/abc181_d
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
  if (s.length() == 1)
  {
    YN(s == "8");
    return;
  }
  else if (s.length() == 2)
  {
    ll num = 0;
    num = stoi(s);
    bool ok = false;
    ok |= (num % 8 == 0);

    swap(s[0], s[1]);

    num = stoi(s);
    ok |= (num % 8 == 0);
    YN(ok);
    return;
  }
  else
  {
    vector<ll> hist(10, 0);
    rep(i, s.length()) hist[(int)(s[i] - '0')]++;
    for(int i = 0; i <= 1000; i += 8)
    {
      vector<ll> histn(10, 0);
      ll log = 1;
      rep(j, 3)
      {
        histn[(i / log) % 10]++;
        log *= 10;
      }
      bool ok = true;
      rep(j, 10)
      {
        ok &= (histn[j] <= hist[j]);
      }
      if (ok)
      {
        YN(ok);
        return;
      }
    }
  }
  YN(false);  
}

int main()
{
  fastio;
  solve();

  return 0;
}