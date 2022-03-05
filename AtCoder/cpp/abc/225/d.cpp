#include <bits/stdc++.h>
#include <atcoder/all>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=(a);i<(ll)(n);++i)
#define repe(i,n) repie(i,0,n)
#define repie(i,a,n) for(ll i=(a);i<=(ll)(n);++i)
#define rrep(i,n) rrepi(i,n,0)
#define rrepi(i,n,a) for(ll i=(n);i>=(a);--i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using namespace atcoder;
using ll = int_fast64_t;
using vl = vector<ll>;
using vvl = vector<vl>;
using P = pair<ll, ll>;
using vp = vector<P>;
using vvp = vector<vp>;
const ll INF = 1LL << 60;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }

struct link {
  ll next;
  ll prev;
  ll val;
};

void solve()
{
  ll n, q;
  cin >> n >> q;

  const ll non = -1;

  vector<link> ls(n);
  rep(i, n)
  {
    ls[i].next = non;
    ls[i].prev = non;
    ls[i].val = i;
  }

  rep(_, q)
  {
    ll v;
    cin >> v;
    if (v == 1)
    {
      ll x, y;
      cin >> x >> y;
      x--; y--;
      ls[x].next = y;
      ls[y].prev = x;
    }
    if (v == 2)
    {
      ll x, y;
      cin >> x >> y;
      x--; y--;
      ls[x].next = non;
      ls[y].prev = non;
    }
    if (v == 3)
    {
      ll x;
      cin >> x;
      x--;
      ll now = x;
      while(ls[now].prev != non)
      {
        now = ls[now].prev;
      }
      vl ans;
      while (now != non)
      {
        ans.push_back(now + 1);
        now = ls[now].next;
      }
      cout << ans.size() << " ";
      showall(ans);
    }
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}
