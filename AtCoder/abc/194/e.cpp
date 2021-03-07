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
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  vector<ll> hist(1500010, 0);

  const ll INF = 1LL << 60;
  ll ans = INF;

  set<P> st;
  st.insert(P(-INF, -INF));
  st.insert(P(INF, INF));
  rep(i, n)
  {
    cin >> a[i];
    hist[a[i]]++;

    // add
    auto itr = st.lower_bound(P(a[i] + 1, a[i] + 1));
    auto p_itr = prev(itr);

    if (!(p_itr->first <= a[i] && a[i] <= p_itr->second))
    {
      ll right = a[i];
      ll left = a[i];
      if (a[i] + 1 == itr->first)
      {
        right = itr->second;
        st.erase(itr);
      }
      if (p_itr->second + 1 == a[i])
      {
        left = p_itr->first;
        st.erase(p_itr);
      }
      if (*p_itr != P(left, right))
      {
        st.insert(P(left, right));
      }
    }

    if (i + 1 >= m)
    {
      // query
      auto q_itr = st.lower_bound(P(0, 0));
      if (q_itr->first == 0) chmin(ans, q_itr->second + 1);
      else { ans = 0; break; }

      // remove
      ll ra = a[i - m + 1];
      hist[ra]--;
      if (hist[ra] <= 0)
      {
        auto r_itr = st.lower_bound(P(ra + 1, ra + 1));
        r_itr = prev(r_itr);

        if (*r_itr == P(ra, ra)) st.erase(r_itr);
        else if (r_itr->first == ra)
        {
          st.insert(P(ra + 1, r_itr->second));
          st.erase(r_itr);
        }
        else if (r_itr->second == ra)
        {
          st.insert(P(r_itr->first, ra - 1));
          st.erase(r_itr);
        }
        else
        {
          ll left = r_itr->first;
          ll right = r_itr->second;
          st.erase(r_itr);
          st.insert(P(left, ra - 1));
          st.insert(P(ra + 1, right));
        }
      }
    }
  }
  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}