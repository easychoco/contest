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

ll h, w;
ll ans = 0;
void dfs(string mp, ll a, ll b)
{
  rep(i, h * w)
  {
    if (mp[i] == '.')
    {
      if (a > 0)
      {
        if (i % w < w - 1)
        {
          string nx = mp;
          nx[i] = 'a';
          nx[i + 1] = 'a';
          dfs(nx, a - 1, b);
        }
        if (i + w < h * w)
        {
          string nx = mp;
          nx[i] = 'a';
          nx[i + w] = 'a';
          dfs(nx, a - 1, b);
        }
      }

      if (b > 0)
      {
        string nx = mp;
        nx[i] = 'b';
        dfs(nx, a, b - 1);
      }

      return;
    }
  }
  ans++;
}

void solve()
{
  ll a, b;
  cin >> h >> w >> a >> b;

  string mp = string(h * w, '.');
  dfs(mp, a, b);
  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}