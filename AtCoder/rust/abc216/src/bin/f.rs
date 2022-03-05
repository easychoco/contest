#[allow(unused_imports)]
use itertools::Itertools;
#[allow(unused_imports)]
use proconio::{fastout, input, marker::Chars};
#[allow(unused_imports)]
use std::cmp::{max, min};
#[allow(unused_imports)]
use std::collections::{BTreeSet, HashMap, HashSet, VecDeque};

#[fastout]
fn main() {
  input! {
    n: usize,
    a: [usize; n],
    b: [usize; n],
  }
  let m = 998244353;
  let mut ab: Vec<(usize, usize)> = vec![(0, 0); n];
  for i in 0..n {
    ab[i] = (a[i], b[i]);
  }
  ab.sort_unstable();

  // dp[i][j] = 0..i を見て、和が j になる組み合わせ
  let mut dp = vec![[0_usize; 5010]; n + 1];
  dp[0][0] = 1;
  for i in 1..=n {
    let (_, b) = ab[i - 1];

    for j in 0..=5000 { // knapsack DP
      dp[i][j] = dp[i - 1][j];
      if j >= b {
        dp[i][j] += dp[i - 1][j - b];
        dp[i][j] %= m;
      }
    }
  }

  let mut ans = 0;
  for i in 0..n {
    let (a, b) = ab[i];
    if a < b { continue; }
    for j in 0..=a-b { // b[i] を足した時に、和が a[i] 以下になる組み合わせ
      ans += dp[i][j];
      ans %= m;
    }
  }

  println!("{}", ans);
}
