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
    b: [usize; n]
  }
  let m = 998244353;
  
  // dp[i] = c の値が i の時の組み合わせ
  let mut dp = vec![1; 3010];

  for i in 0..n {
    let mut next_dp = vec![0; 3010];
    for v in a[i]..=b[i] {
      next_dp[v] = dp[v]
    }
    for v in 0..=3000 {
      next_dp[v + 1] += next_dp[v];
      next_dp[v + 1] %= m;
    }
    dp = next_dp;
  }
  println!("{}", dp[b[n - 1]]);
}
