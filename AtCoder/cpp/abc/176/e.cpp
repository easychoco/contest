#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  ll h, w, m, hin, win;
  cin >> h >> w >> m;
  vector<ll> ah(h + 1, 0);
  vector<ll> aw(w + 1, 0);
  set<ll> hash;
  for(int i = 0; i < m; ++i)
  {
    cin >> hin >> win;
    ah[hin]++;
    aw[win]++;
    hash.insert((hin << 32LL) + win);
  }
  ll ah_max_ind = distance(ah.begin(), max_element(ah.begin(), ah.end()));
  ll aw_max_ind = distance(aw.begin(), max_element(aw.begin(), aw.end()));

  vector<ll> ah_ind;
  vector<ll> aw_ind;
  for(int i = 0; i <= h; ++i)
  {
    if (ah[i] == ah[ah_max_ind])
    {
      ah_ind.emplace_back(i);
    }
  }
  for(int i = 0; i <= w; ++i)
  {
    if (aw[i] == aw[aw_max_ind])
    {
      aw_ind.emplace_back(i);
    }
  }

  ll ans = ah[ah_max_ind] + aw[aw_max_ind];
  for(const auto& ih : ah_ind) for(const auto& iw : aw_ind)
  {
    if (hash.find( (ih << 32LL) + iw ) == hash.end())
    {
      cout << ans;
      return;
    }
  }
  cout << ans - 1;
}

int main()
{
  fastio;
  solve();

  return 0;
}