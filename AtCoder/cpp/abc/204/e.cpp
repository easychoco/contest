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

using T = tuple<ll, ll, ll>;

void solve()
{
  ll n, m;
  cin >> n >> m;
  vector<vector< T > > graph(n, vector<T>());
  rep(i, m)
  {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    a--; b--;
    graph[a].emplace_back(make_tuple(b, c, d));
    graph[b].emplace_back(make_tuple(a, c, d));
  }

  const ll INF = 1LL << 60;
  vector<ll> d(n, INF);
  d[0] = 0;
  priority_queue<P, vector<P>, greater<P>> que;
  que.push(P(0, 0)); // P(time, start)
  while (!que.empty())
  {
    P p = que.top();
    que.pop();

    ll time, now;
    tie(time, now) = p;

    if (d[now] < p.first) continue;
    for (const auto& edge : graph[now])
    {
      ll to, cc, dd;
      tie(to, cc, dd) = edge;

      ll nc = time + cc + dd / (time + 1);
      ll sq = (ll)sqrt(dd); // この時間に出発すれば一番早く目的地に着く
      if (time <= sq) // sq - time 待つことになる / else なら、待てば待つほど遅くなるので即時出発する
      repie(t, max(0LL, sq - 1), sq + 1)
      {
        chmin(nc, t + cc + dd / (t + 1));
      }

      if (chmin(d[to], nc))
      {
        que.push(P(d[to], to));
      }
    }
  }
  show(d[n - 1] == INF ? -1 : d[n - 1]);
}

int main()
{
  fastio;
  solve();

  return 0;
}