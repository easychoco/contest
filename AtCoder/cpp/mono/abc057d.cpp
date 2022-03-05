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
#define pb push_back
#define eb emplace_back

using namespace std;
using namespace atcoder;
using vb = vector<bool>;
using vvb = vector<vb>;
using ll = int_fast64_t;
using vl = vector<ll>;
using vvl = vector<vl>;
using P = pair<ll, ll>;
using vp = vector<P>;
using vvp = vector<vp>;
using T = tuple<ll, ll, ll>;
using vt = vector<T>;
const ll INF = 1LL << 55;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
void showd(double d){ cout << std::fixed<<setprecision(13) << d << endl; }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }
void debug(){ cerr << endl; }
template <class Head, class... Tail>
void debug(Head&& head, Tail&&... tail){ cerr << head << " "; debug(std::forward<Tail>(tail)...); }

// nCr を計算する
vvl comb(ll n) {
  vvl ret(n + 1, vl(n + 1, 0));
  repe(i, n) {
    ret[i][0] = 1;
    ret[i][i] = 1;
  }
  repie(j, 1, n)
  repi (k, 1, j) ret[j][k] = (ret[j - 1][k - 1] + ret[j - 1][k]);
  return ret;
}

void solve()
{
  ll n, a, b;
  cin >> n >> a >> b;
  vl v(n);
  map<ll, ll> hist;
  rep(i, n)
  {
    ll v;
    cin >> v;
    hist[v]++;
  }

  vvl c = comb(50);

  ll total_cnt = 0;
  ll sum = 0;
  // 数字の大きい順に
  for(auto itr = hist.rbegin(); itr != hist.rend(); ++itr)
  {
    auto [num, cnt] = *itr;

    // 全部足しても a 未満なら
    if (total_cnt + cnt < a)
    {
      total_cnt += cnt;
      sum += num * cnt;
    }
    // 足した時に a を超えるなら
    // 1週目
    else if (total_cnt == 0)
    {
      show(num);
      ll ans = 0;
      repie(i, a, min(cnt, b))
      {
        ans += c[cnt][i];
        // show(cnt, i, ans, c[cnt][i]);
      }
      show(ans);
      return;
    }
    // 2週目以降
    else
    {
      ll rest = a - total_cnt;
      total_cnt += rest;
      sum += rest * num;
      showd(sum / (double)total_cnt);
      show(c[cnt][rest]);
      return;
    }
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}
