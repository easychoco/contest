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

  // 取り除く文字数
  ll cnt = n - k;

  // 内定した文字をここに入れる
  deque<char> deq;
  for(auto c : s)
  {
    // 文字がないか、これ以上取り除けないとき
    if (deq.empty() || cnt == 0)
    {
      deq.push_back(c);
      continue;
    }

    char back = deq.back();
    // いまの文字(c)が最後尾よりも辞書順で小さい場合は
    // 最後尾をいまの文字に差し替える
    while(back > c && cnt > 0)
    {
      deq.pop_back();
      cnt--;
      if (deq.empty()) break;
      back = deq.back();
    }
    // いまの文字(c)を最後尾に加える
    deq.push_back(c);
  }

  // deq の先頭から k 文字が答え
  string ans = "";
  rep(i, k)
  {
    ans += deq.front();
    deq.pop_front();
  }
  show(ans);
}

int main()
{
  fastio;
  solve();

  return 0;
}