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
void YN(bool a) { cout << (a ? "Yes" : "No"); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }

void solve()
{
	ll n, k;
	cin >> n >> k;

	vector<ll> na;
	vector<ll> pa;
  ll za = 0;
	for(int i = 0; i < n; ++i)
	{
  	ll a;
		cin >> a;
    if (a == 0) za++;
    else if (a > 0) pa.emplace_back(a);
    else na.emplace_back(-a);
	}

  sort(ALL(pa));
  sort(ALL(na));

  ll n_num = 0;
  ll z_num = 0;
  ll p_num = 0;

  n_num = pa.size() * na.size();
  z_num = za * (pa.size() + na.size()) + za * (za - 1) / 2;
  p_num = pa.size() * (pa.size() - 1) / 2 + na.size() * (na.size() - 1) / 2;

  cerr << ((n_num + z_num + p_num == n * (n - 1) / 2) ? "Yes" : "No") << endl;

  if (k <= n_num)
  {
    k = n_num - k;
    auto f = [&](ll arg)
    {
      ll sum = 0;
      rep(i, pa.size())
      {
        auto g = [&](ll ind)
        {
          if (ind == 0) return true;
          return pa[i] * na[ind - 1] <= arg;
        };
        ll ac = 0, wa = na.size() + 1;
        while(wa - ac > 1) // arg 以下の数字が wj個ある
        {
          ll wj = (ac + wa) / 2;
          if ( g(wj) ) ac = wj;
          else wa = wj;
        }
        sum += ac;
      }
      return sum <= k;
    };
    ll ac = 0, wa = pa.back() * na.back() + 1;
    while(wa - ac > 1) // wj が前から k 番目以下である
    {
      ll wj = (ac + wa) / 2;
      if ( f(wj) ) ac = wj;
      else wa = wj;
    }
    show(-wa);
    return;
  }
  else if (k <= n_num + z_num)
  {
    show(0);
    return;
  }
  else
  {
    k -= n_num + z_num;
    auto f = [&](ll arg)
    {
      ll sum = 0;
      rep(i, pa.size())
      {
        auto g = [&](ll ind)
        {
          if (ind == 0) return true;
          ll idx = i + ind;
          return pa[i] * pa[idx] <= arg;
        };
        ll ac = 0, wa = pa.size() - i;
        while(wa - ac > 1) // arg 以下の数字が wj個ある
        {
          ll wj = (ac + wa) / 2;
          if ( g(wj) ) ac = wj;
          else wa = wj;
        }
        sum += ac;
      }

      rep(i, na.size())
      {
        auto g = [&](ll ind)
        {
          if (ind == 0) return true;
          ll idx = i + ind;
          return na[i] * na[idx] <= arg;
        };
        ll ac = 0, wa = na.size() - i;
        while(wa - ac > 1) // arg 以下の数字が wj個ある
        {
          ll wj = (ac + wa) / 2;
          if ( g(wj) ) ac = wj;
          else wa = wj;
        }
        sum += ac;
      }
      return sum < k;
    };
    ll ac = 0, wa = 1'001'001'001'001'001'001;
    while(wa - ac > 1) // wj が前から k 番目以下である
    {
      ll wj = (ac + wa) / 2;
      if ( f(wj) ) ac = wj;
      else wa = wj;
    }
    show(wa);
    return;
  }
}

int main()
{
	fastio;
	solve();

	return 0;
}