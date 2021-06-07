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
  ll n, k;
  string s;
  cin >> n >> k >> s;
  ll cnt = n - k;
  stack<char> st;
  for(auto c : s)
  {
    if (st.empty()) st.push(c);
    else if (cnt == 0) st.push(c);
    else
    {
      char top = st.top();
      while(top > c && cnt > 0)
      {
        st.pop();
        cnt--;
        if (st.empty()) break;
        top = st.top();
      }
      st.push(c);
    }
  }
  string ans = "";
  while(!st.empty())
  {
    if (cnt == 0) ans += st.top();
    else cnt--;
    st.pop();
  }
  reverse(ALL(ans));

  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}