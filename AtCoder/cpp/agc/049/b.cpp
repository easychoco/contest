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

void solve()
{
  ll n;
  string s, t;
  cin >> n >> s >> t;
  queue<ll> sq, tq;
  rep(i, n) if (s[i] == '1') sq.push(i);
  rep(i, n) if (t[i] == '1') tq.push(i);

  // s と t の 1 の個数の偶奇が合わない = サイズの和が奇数なら
  if ((sq.size() + tq.size()) & 1)
  {
    cout << -1 << endl;
    return;
  }

  // 横並びの１を消す
  // 1をひとつ左にずらす

  ll ans = 0;
  while(1)
  {
    if (tq.empty())
    {
      //sの残りを消す
      while(!sq.empty())
      {
        ll s1 = sq.front();
        sq.pop();
        ll s2 = sq.front();
        sq.pop();
        ans += s2 - s1;
      }
      break;
    }

    if (sq.empty())
    {
      cout << -1 << endl;
      return;
    }

    ll sf = sq.front();
    ll tf = tq.front();

    if (sf == tf)
    {
      sq.pop();
      tq.pop();
    }
    else if (sf < tf)
    {
      if (sq.size() == 1)
      {
        cout << -1 << endl;
        return;
      }

      // sの先頭2つを消す
      sq.pop();
      ll sn = sq.front();
      sq.pop();
      ans += sn - sf;
    }
    else if (tf < sf)
    {
      // sの先頭とtの先頭を合わせる
      ans += sf - tf;
      sq.pop();
      tq.pop();
    }
  }

  cout << ans << endl;

}

int main()
{
  fastio;
  solve();

  return 0;
}