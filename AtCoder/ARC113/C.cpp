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

void solve()
{
  string s;
  cin >> s;

  ll sz = s.length();
  string imos = string(sz, '-');
  repi(i, 2, sz)
  {
    if (s[i - 2] == s[i - 1] && s[i - 1] != s[i])
    {
      imos[i] = s[i - 1];
    }
  }

  char now = '-';
  ll minus = 0;
  vector<ll> sum(sz, 0);
  rep(i, sz)
  {
    if (imos[i] != now && imos[i] != '-')
    {
      sum[i] = 1;
      now = imos[i];

      ll idx = i + 1;
      while((imos[idx] == '-' || imos[idx] == now) && idx < sz)
      {
        if (s[idx] == now)
        {
          minus++;
        }
        idx++;
      }
      i = idx - 1;
    }
  }

  repi(i, 1, sz)
  {
    sum[i] += sum[i - 1];
  }
  repi(i, 1, sz)
  {
    sum[i] += sum[i - 1];
  }
  show(sum.back() - minus);
}

int main()
{
  fastio;
  solve();

  return 0;
}