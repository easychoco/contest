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
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

void solve()
{
  string s;
  int x, y;
  cin >> s >> x >> y;
  vector<int> hor;
  vector<int> ver;
  s += "T";
  bool isHorizon = true;
  int len = 0;
  rep(i, s.size())
  {
    if (s[i] == 'F') len++;
    else if (s[i] == 'T')
    {
      (isHorizon ? hor : ver).emplace_back(len);
      len = 0;
      isHorizon = !isHorizon;
    }
  }
  
  ll h_sum = accumulate(ALL(hor), 0LL);
  ll v_sum = accumulate(ALL(ver), 0LL);

  vector<bool> dph(h_sum * 2 + 1, false);
  vector<bool> dpv(v_sum * 2 + 1, false);

  dph[h_sum + hor[0]] = true;
  dpv[v_sum] = true;

  repi(i, 1, hor.size())
  {
    vector<bool> next(h_sum * 2 + 1, false);
    rep(j, h_sum * 2 + 1)
    {
      if (dph[j])
      {
        next[j + hor[i]] = true;
        next[j - hor[i]] = true;
      }
    }
    dph = next;
  }

  rep(i, ver.size())
  {
    vector<bool> next(v_sum * 2 + 1, false);
    rep(j, v_sum * 2 + 1)
    {
      if (dpv[j])
      {
        next[j + ver[i]] = true;
        next[j - ver[i]] = true;
      }
    }
    dpv = next;
  }

  bool ok = true;
  if (y + v_sum < 0 || v_sum * 2 < y + v_sum) ok = false;
  else if (x + h_sum < 0 || h_sum * 2 < x + h_sum) ok = false;
  else ok = (dpv[y + v_sum] & dph[x + h_sum]);
  YN(ok);
}

int main()
{
  fastio;
  solve();

  return 0;
}