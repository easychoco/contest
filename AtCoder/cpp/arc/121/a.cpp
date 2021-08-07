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
  ll n;
  cin >> n;

  vector<tuple<ll,ll>> x(n), y(n);
  rep(i, n) {
    ll xx, yy;
    cin >> xx >> yy;
    x[i] = make_tuple(xx, i);
    y[i] = make_tuple(yy, i);
  }
  sort(ALL(x));
  sort(ALL(y));

  priority_queue<tuple<ll, ll, ll>> que;
  {
    ll xx0, i0, xx1, i1, xxn1, in1, xxn2, in2;
    tie(xx0, i0) = x[0];
    tie(xx1, i1) = x[1];
    tie(xxn2, in2) = x[n - 2];
    tie(xxn1, in1) = x[n - 1];
    que.emplace(xxn1 - xx0, min(in1, i0), max(in1, i0));
    que.emplace(xxn1 - xx1, min(in1, i1), max(in1, i1));
    que.emplace(xxn2 - xx0, min(in2, i0), max(in2, i0));
    que.emplace(xxn2 - xx1, min(in2, i1), max(in2, i1));
  }
  {
    ll yy0, i0, yy1, i1, yyn1, in1, yyn2, in2;
    tie(yy0, i0) = y[0];
    tie(yy1, i1) = y[1];
    tie(yyn2, in2) = y[n - 2];
    tie(yyn1, in1) = y[n - 1];
    que.emplace(yyn1 - yy0, min(in1, i0), max(in1, i0));
    que.emplace(yyn1 - yy1, min(in1, i1), max(in1, i1));
    que.emplace(yyn2 - yy0, min(in2, i0), max(in2, i0));
    que.emplace(yyn2 - yy1, min(in2, i1), max(in2, i1));
  }
  ll d, i1, i2;
  tie(d, i1, i2) = que.top();
  que.pop();
  ll dd, ii1, ii2;
  tie(dd, ii1, ii2) = que.top();
  que.pop();
  if (d != dd)
  {
    show(dd);
    return;
  }
  if (i1 == ii1 && i2 == ii2)
  {
    tie(dd, ii1, ii2) = que.top();
    show(dd);
    return;
  }
  show(dd);
}

int main()
{
  fastio;
  solve();

  return 0;
}