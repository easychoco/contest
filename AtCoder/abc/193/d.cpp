#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=a;i<(ll)n;++i)
#define repe(i,n) repie(i,0,n)
#define repie(i,a,n) for(ll i=a;i<=(ll)n;++i)
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

constexpr int ten[6] = { 1, 10, 100, 1000, 10000, 100000 };
ll score(vector<ll> &v)
{
  ll ret = 0;
  repie(i, 1, 9)
  {
    ret += i * ten[v[i]];
  }
  return ret;
}

void solve()
{
  ll k;
  string s, t;
  cin >> k >> s >> t;

  vector<ll> hist_s(10, 0);
  vector<ll> hist_t(10, 0);
  vector<ll> hist_all(10, 0);
  rep(i, 4) hist_s[(int)(s[i] - '0')]++;
  rep(i, 4) hist_t[(int)(t[i] - '0')]++;
  repie(i, 1, 9) hist_all[i] = hist_s[i] + hist_t[i];

  ll bunbo = (9 * k - 8) * (9 * k - 9);
  ll bunsi = 0;
  repie(si, 1, 9)
  {
    repie(ti, 1, 9)
    {
      if (si == ti && hist_all[si] + 2 > k) continue;
      if (hist_all[si] + 1 > k || hist_all[ti] + 1 > k) continue;

      vector<ll> ss(hist_s);
      vector<ll> tt(hist_t);
      ss[si]++;
      tt[ti]++;
      if (score(ss) > score(tt)) 
      {
        ll rest_si = k - hist_all[si];
        ll rest_ti = k - hist_all[ti];
        if (si == ti) rest_ti--;
        bunsi += (rest_si * rest_ti);
      }
    }
  }
  printf("%.7lf\n", (bunsi / (double)bunbo));
}

int main()
{
  fastio;
  solve();

  return 0;
}
