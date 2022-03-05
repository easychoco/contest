#include <bits/stdc++.h>
#include <atcoder/all>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define rep(i,n) repi(i,0,n)
#define repi(i,a,n) for(ll i=(a);i<(ll)(n);++i)
#define repe(i,n) repie(i,0,n)
#define repie(i,a,n) for(ll i=(a);i<=(ll)(n);++i)
#define rrep(i,n) rrepi(i,n,0)
#define rrepi(i,n,a) for(ll i=(n);i>=(a);--i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using namespace atcoder;
using namespace chrono;
// using ll = int_fast64_t;
using ll = int;
using vl = vector<ll>;
using vvl = vector<vl>;
using P = pair<ll, ll>;
using vp = vector<P>;
using vvp = vector<vp>;
const ll INF = 1LL << 60;
void YN(bool a) { cout << (a ? "Yes" : "No") << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
void show(){ cout << endl; }
template <class Head, class... Tail>
void show(Head&& head, Tail&&... tail){ cout << head << " "; show(std::forward<Tail>(tail)...); }
template<class T> inline void showall(T& a) { for(auto v:a) cout<<v<<" "; cout<<endl; }

// https://atcoder.jp/contests/intro-heuristics/submissions/15983533

// 0以上 UINT_MAX(0xffffffff)以下の整数をとる乱数 xorshift https://ja.wikipedia.org/wiki/Xorshift
static uint32_t randXor()
{
    static uint32_t x = 123456789;
    static uint32_t y = 362436069;
    static uint32_t z = 521288629;
    static uint32_t w = 88675123;
    uint32_t t;
 
    t = x ^ (x << 11);
    x = y; y = z; z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}
 
// 0以上1未満の小数をとる乱数
static double rand01()
{
    return (randXor() + 0.5) * (1.0 / UINT_MAX);
}
 
const static ll NUM_TYPES = 26; // コンテストの種類数
 
// 全体のスコア（今回の問題のスコア）
static ll calc_score()
{
  return 0;
}
 
void solve()
{
  // 焼きなまし法（ここから）
  auto startClock = system_clock::now();
  ll score = calc_score();      // 現在のスコア
  ll bestScore = INT_MIN;       // 最高スコア
  vl elite;                     // 最高スコアを出したときのT

  const static double START_TEMP = 1500; // 開始時の温度
  const static double END_TEMP   =  100; // 終了時の温度
  const static double END_TIME   =  1.8; // 終了時間（秒）

  double time = 0.0;   // 経過時間（秒）

  vl seq;
  do
  {
    vl prev = seq;
    const double progress_ratio = time / END_TIME;   // 進捗。開始時が0.0、終了時が1.0
    const double temp = START_TEMP + (END_TEMP - START_TEMP) * progress_ratio;

    ll deltaScore = 0; // スコアの差分 = 変更後のスコア - 変更前のスコア
    // 変更前
    deltaScore -= calc_score();
    
    // ここで変更する

    // 変更後
    deltaScore += calc_score();
    const double probability = exp(deltaScore / temp); // 焼きなまし法の遷移確率

    if (probability > rand01())
    {
      // 変更を受け入れる。スコアを更新
      score += deltaScore;
      if (score > bestScore)
      {
        bestScore = score;
        elite = seq;
      }
    }
    else
    {
      // 変更を受け入れないので、元に戻す
    }

    time = (duration_cast<microseconds>(system_clock::now() - startClock).count() * 1e-6);
  } while (time < END_TIME);
  // 焼きなまし法（ここまで）
}

ll main()
{
  fastio;
  solve();

  return 0;
}
