#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

// 最大公約数 : 3,4 ->  1
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }


void solve()
{
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  for(int i = 0; i < m; ++i)
  {
    cin >> a[i];
  }

  // P(数字, コスト)
  // コストが低い順、同じ場合は数字が大きい順に手動ソート
  const vector<P> num{
    P(1, 2),
    P(7, 3),
    P(4, 4),
    P(5, 5),
    P(3, 5),
    P(2, 5),
    P(9, 6),
    P(6, 6),
    P(8, 7)
  };

  vector<P> deck;
  for(const auto& _num : num)
  {
    for(int i = 0; i < m; ++i)
    {
      if ( deck.size() > 0 && (a[i] == 2 || a[i] == 3) )
      {
        if (deck.back().second == 5) continue;
      }
      if ( deck.size() > 0 && a[i] == 6 )
      {
        if (deck.back().second == 6) continue;
      }

      if (a[i] == _num.first)
      {
        deck.emplace_back(_num);
        break;
      }
    }
  }

  queue< pair<int, vector<int>> > que;
  que.push(make_pair(0, vector<int>()));

  vector<int> ans;

  while(!que.empty())
  {
    auto now = que.front();
    que.pop();

    if (now.first == n)
    {
      if(ans.size() < now.second.size())
      ans = now.second;
    }
    if (now.first >= n) continue;

    if ((n - now.first) % deck[0].second == 0)
    {
      for(int i = 0; i < (n - now.first) / deck[0].second; ++i)
      {
        now.second.emplace_back(deck[0].first);
      }
      ans = now.second;
      break;
    }

    for(const auto& d : deck)
    {
      vector<int> next_v(now.second);
      next_v.emplace_back(d.first);
      pair<int, vector<int>> next = make_pair(now.first + d.second, next_v);
      que.push(next);
    }
  }

  sort(ans.begin(), ans.end(), greater<int>());
  for(const auto& _ans : ans) cout << _ans;
}

int main()
{
  fastio;
  solve();

  return 0;
}