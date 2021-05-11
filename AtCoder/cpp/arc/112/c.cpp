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

vector<ll> sz;
vector<vector<ll>> child;

int dfs(int idx)
{
  sz[idx] = 1;
  for(auto to : child[idx])
  {
    sz[idx] += dfs(to);
  }
  return sz[idx];
}

int count(int idx) // idxの頂点に来た時に手番のある人が、また戻ってきたときの相対スコア
{
  vector<ll> odd;
  vector<ll> even;
  ll score = -1;
  for(auto to : child[idx]) ((sz[to] & 1) ? odd : even).emplace_back(count(to));

  sort(RALL(odd));
  int sign = 1;
  for(auto v : odd)
  {
    score += sign * v;
    sign *= -1;
  }

  for(auto v : even)
  {
    if (v >= 0) score += v;
    else score += v * ((odd.size() & 1) ? -1 : 1);
  }
  return score;
}

void solve()
{
  ll n;
  cin >> n;
  sz.resize(n, 0);
  child.resize(n, vector<ll>());
  repi(i, 1, n)
  {
    ll p;
    cin >> p;
    p--;
    child[p].emplace_back(i);
  }

  dfs(0);
  show((n - count(0)) / 2);
}

int main()
{
  fastio;
  solve();

  return 0;
}