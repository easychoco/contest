#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

bool isPrime(int a) {
    if (a == 1) return false;
    for (int i = 2; i * i <= a; i++) {
        if(a % i == 0) return false;
    }
    return true;
}

void solve()
{
  int n;
  cin >> n;

  vector<int> ans{2};
  int num = 1;
  while(ans.size() < n)
  {
    num += 10;
    if (isPrime(num)) ans.emplace_back(num);
  }
  for(const auto& v : ans)
  {
    cout << v << " ";
  }

  /*
  // これでも可w
  vector<int> ans{2, 11, 31, 41, 61, 71, 101, 131, 151, 181, 191, 211, 241, 251, 271, 281, 311, 331, 401, 421, 431, 461, 491, 521, 541, 571, 601, 631, 641, 661, 691, 701, 751, 761, 811, 821, 881, 911, 941, 971, 991, 1021, 1031, 1051, 1061, 1091, 1151, 1171, 1181, 1201, 1231, 1291, 1301, 1321, 1361};
  for(int i = 0; i < n; ++i)
  {
    cout << ans[i] << " ";
  }
  */
}

int main()
{
  fastio;
  solve();

  return 0;
}