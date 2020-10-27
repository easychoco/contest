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
  ll l;
  cin >> l;

  // tuple<from, to, weight>
  vector< tuple<ll, ll, ll> > graph;

  // tuple<from, weight>
  vector< tuple<ll, ll> > post;

  ll pow[21] = {0, 1, };
  repi(i, 2, 21) pow[i] = 1<<(i-1);

  ll from = 1;
  ll to = 2;
  ll lv = 1;
  while(l > 1)
  {
    if (l % 2 == 1)
    {
      post.emplace_back(from, pow[lv] * (l - 1));
    }
    graph.emplace_back(from, to, 0);
    graph.emplace_back(from, to, pow[lv]);
    from++;
    to++;
    lv++;
    l /= 2;
  }

  to--;
  for(auto p : post)
  {
    ll f, w;
    tie(f, w) = p;
    graph.emplace_back(f, to, w);
  }

  cout << to << " " << graph.size() << endl;
  for(auto tup : graph)
  {
    ll f, t, w;
    tie(f, t, w) = tup;
    cout << f << " " << t << " " << w << endl;
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}