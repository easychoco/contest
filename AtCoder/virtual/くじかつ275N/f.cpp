// https://atcoder.jp/contests/abc166/tasks/abc166_f
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

void solve()
{
  ll n, a, b, c;
  cin >> n >> a >> b >> c;

  if (a + b + c == 0)
  {
    YN(false);
    return;
  }

  map<char, int> mp;
  mp['A'] = a;
  mp['B'] = b;
  mp['C'] = c;
  
  vector<string> ss(n);
  rep(i, n) cin >> ss[i];

  if (a + b + c == 1)
  {
    string ans = "";
    rep(i, n)
    {
      if (mp[ss[i][0]] + mp[ss[i][1]] == 0)
      {
        YN(false);
        return;
      }
      else
      {
        if (mp[ss[i][0]] == 0) ans += ss[i][0];
        else ans += ss[i][1];
        swap(mp[ss[i][0]], mp[ss[i][1]]);
      }
    }
    YN(true);
    rep(i, n) show(ans[i]);
    return;
  }

  // if (a + b + c >= 2)

  if(mp[ss[0][0]] + mp[ss[0][1]] == 0)
  {
    YN(false);
    return;
  }

  YN(true);
  rep(i, n)
  {
    // ss[i][0] から引くか
    bool first = true;

    if (mp[ss[i][0]] >= 2)
    {
      first = true;
    }
    else if (mp[ss[i][0]] == 0)
    {
      first = false;
    }
    else if (mp[ss[i][0]] == 1)
    {
      if (mp[ss[i][1]] >= 2)
      {
        first = false;
      }
      else if (mp[ss[i][1]] == 0)
      {
        first = true;
      }
      else // if (mp[ss[i][1] == 1)
      {
        if (i == n - 1)
        {
          first = true;
        }
        else
        {
          first = !(ss[i][0] == ss[i + 1][0] || ss[i][0] == ss[i + 1][1]);
        }
      }
    }

    
    if (first)
    {
      show(ss[i][1]);
      mp[ss[i][0]]--;
      mp[ss[i][1]]++;
    }
    else
    {
      show(ss[i][0]);
      mp[ss[i][0]]++;
      mp[ss[i][1]]--;
    }
  }
}

int main()
{
  fastio;
  solve();

  return 0;
}