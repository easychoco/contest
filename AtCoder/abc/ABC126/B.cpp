#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

void solve()
{
  int s;
  cin >> s;

  int front = s / 100;
  int back = s % 100;

  bool yymm = (front < 100) && (0 < back) && (back <= 12);
  bool mmyy = (0 < front) && (front <= 12) && (back < 100);

  if (yymm && mmyy) cout << "AMBIGUOUS";
  else if (yymm) cout << "YYMM";
  else if (mmyy) cout << "MMYY";
  else cout << "NA";
}

int main()
{
	fastio;
	solve();

	return 0;
}