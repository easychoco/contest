// https://atcoder.jp/contests/agc034/tasks/agc034_b
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

  ll sz = s.length();
  const string bc = "BC";

  vector<ll> ss;

  ll ans = 0;
  rep(i, sz)
  {
    if (s[i] == 'A')
    {
      ss.emplace_back(0);
    }
    else if (s.substr(i, 2) == bc)
    {
      ss.emplace_back(1);
      i++;
    }
    else
    {
      ll goal = 0;
      rep(j, ss.size())
      {
        if (ss[j] == 1)
        {
          ans += j - goal;
          goal++;
        }
      }
      ss.resize(0);
    }
  }

  ll goal = 0;
  rep(j, ss.size())
  {
    if (ss[j] == 1)
    {
      ans += j - goal;
      goal++;
    }
  }
  ss.resize(0);

  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}