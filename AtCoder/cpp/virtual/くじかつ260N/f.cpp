// https://atcoder.jp/contests/abc167/tasks/abc167_f
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

void solve()
{
  ll n;
  cin >> n;

  ll left = 0;
  ll right = 0;
  ll cc = 0;
  vector<P> cn;
  vector<P> cp;

  rep(ii, n)
  {
    ll l = 0;
    ll r = 0;

    string s;
    cin >> s;

    rep(i, s.length())
    {
      if (s[i] == '(')
      {
        l++;
      }
      if (s[i] == ')')
      {
        if (l > 0) l--;
        else r++;
      }
    }

    if (l > 0 && r > 0)
    {
      if (l == r) chmax(cc, l);
      else
      {
        if (l - r < 0) cn.emplace_back(P(l, r));
        else cp.emplace_back(P(r, l));
      }
    }
    else if (l > 0) left += l;
    else if (r > 0) right += r;
  }

  sort(ALL(cp));
  sort(ALL(cn));

  ll le = left;
  ll re = right;

  rep(i, cp.size())
  {
    le -= cp[i].first;
    if (le < 0)
    {
      YN(false);
      return;
    }
    le += cp[i].second;
  }
  rep(i, cn.size())
  {
    re -= cn[i].first;
    if (re < 0)
    {
      YN(false);
      return;
    }
    re += cn[i].second;
  }



  YN(le == re && le >= cc);

}

int main()
{
  fastio;
  solve();

  return 0;
}