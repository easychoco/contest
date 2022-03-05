// https://atcoder.jp/contests/abc222/tasks/abc222_c
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

int battle(char c1, char c2)
{
  if (c1 == c2) return 0;
  if (c1 == 'G' && c2 == 'C') return 1;
  if (c1 == 'G' && c2 == 'P') return 2;
  if (c1 == 'C' && c2 == 'G') return 2;
  if (c1 == 'C' && c2 == 'P') return 1;
  if (c1 == 'P' && c2 == 'G') return 1;
  if (c1 == 'P' && c2 == 'C') return 2;

  return -10;
}

void solve()
{
  ll n, m;
  cin >> n >> m;
  vector<string> a(2 * n);
  rep(i, 2 * n) cin >> a[i];

  vp score(2 * n);
  rep(i, 2 * n)
  {
    score[i] = P(0, -i);
  }

  rep(i, m)
  {
    rep(j, n)
    {
      ll p1 = -score[j * 2].second;
      ll p2 = -score[j * 2 + 1].second;
      ll res = battle(a[p1][i], a[p2][i]);

      if (res == 1) score[j * 2].first++;
      if (res == 2) score[j * 2 + 1].first++;
    }
    sort(RALL(score));
  }
  rep(i, n * 2)
  {
    show(-score[i].second + 1);
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}
