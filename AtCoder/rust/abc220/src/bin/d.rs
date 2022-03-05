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
    a: [usize; n]
  }
 
  let m = 998244353;

  // dp[i] = 左端が i の時の組み合わせ
  let mut dp = vec![0; 10];
  dp[a[0]] = 1;
  for i in 1..n {
    let mut next = vec![0; 10];
    for j in 0..10 {
      next[(a[i] + j) % 10] += dp[j];
      next[(a[i] + j) % 10] %= m;
      next[(a[i] * j) % 10] += dp[j];
      next[(a[i] * j) % 10] %= m;
    }
   dp = next;
  }
  for i in 0..10 {
    println!("{}", dp[i]);
  }
}
