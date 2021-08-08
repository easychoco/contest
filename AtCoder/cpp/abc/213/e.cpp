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
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using P = pair<ll, ll>;
const ll INF = 1LL << 60;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }

void solve()
{
  ll h, w;
  cin >> h >> w;
  vector<string> mp(h);
  rep(i, h)
  {
    cin >> mp[i];
  }

  vector<vector<ll>> come(h, vector<ll>(w, INF));

  const ll dy[4] = { 0, 1, 0, -1 };
  const ll dx[4] = { 1, 0, -1, 0 };

  const ll py[4][5] = {
    { -1, -1, 0, 1, 1 },
    { 0, 0, 1, 1, 1 },
    { -1, -1, 0, 1, 1 },
    { -1, -1, -1, 0, 0 },
  };
  const ll px[4][5] = {
    { 0, 1, 1, 0, 1 },
    { -1, 1, -1, 0, 1 },
    { -1, 0, -1, -1, 0 },
    { -1, 0, 1, -1, 1 },
  };

  // P(pos, count)
  deque<P> que;
  que.push_front(P(0, 0));
  come[0][0] = true;
  while(!que.empty())
  {
    ll now, cnt;
    tie(now, cnt) = que.front();
    que.pop_front();

    // show(now, cnt);
    if (now == h * w - 1)
    {
      show(cnt);
      return;
    }

    ll y = now / w;
    ll x = now % w;

    rep(i, 4)
    {
      ll ny = y + dy[i];
      ll nx = x + dx[i];
      if (ny < 0 || h <= ny) continue;
      if (nx < 0 || w <= nx) continue;
      if (come[ny][nx] <= cnt) continue;

      if (mp[ny][nx] == '.')
      {
        ll next = ny * w + nx;
        que.push_front(P(next, cnt));
        come[ny][nx] = cnt;
      }
      else
      {
        rep(ii, 5)
        {
          ll nny = ny + py[i][ii];
          ll nnx = nx + px[i][ii];
          if (nny < 0 || h <= nny) continue;
          if (nnx < 0 || w <= nnx) continue;
          if (come[nny][nnx] <= cnt + 1) continue;
          ll next = nny * w + nnx;
          que.push_back(P(next, cnt + 1));
          come[nny][nnx] =cnt + 1;
        }
      }
    }
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}