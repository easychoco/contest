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
void YN(bool a) { cout << (a ? "Yes" : "No"); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

void solve()
{
  ll n, a;
  cin >> n;
  priority_queue< int, vector<int>, greater<int> > a1;	// 最小値から出てくるヒープ 
  vector<ll> a2(n);
  priority_queue<int> a3;	// 最大値から出てくるヒープ
  vector<ll> score(n + 1, 0);

  ll sum_a1 = 0;
  ll sum_a3 = 0;
  rep(i, n)
  {
    cin >> a;
    sum_a1 += a;
    a1.push(a);
  }
  rep(i, n)
  {
    cin >> a2[i];
  }
  rep(i, n)
  {
    cin >> a;
    sum_a3 += a;
    a3.push(a);
  }

  score[0] += sum_a1;
  score[n] -= sum_a3;
  rep(i, n)
  {
    a1.push(a2[i]);
    sum_a1 += a2[i] - a1.top();
    score[i + 1] += sum_a1;
    a1.pop();

    ll j = n - i - 1;
    a3.push(a2[j]);
    sum_a3 += a2[j] - a3.top();
    score[j] -= sum_a3;
    a3.pop();
  }
  cout << *max_element(ALL(score));
}

int main()
{
  fastio;
  solve();

  return 0;
}