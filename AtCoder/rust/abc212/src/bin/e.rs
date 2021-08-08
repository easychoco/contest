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
    m: usize,
    k: usize,
    uv: [(usize, usize); m]
  }

  let m = 998244353;
  let mut dp = vec![0; n];
  dp[0] = 1;
  for _ in 0..k {
    let sum: i64 = dp.iter().sum();
    
    // 道が1つも壊れていない場合の数を計算する
    let mut next = dp.iter().map(|v| sum - v).collect::<Vec<_>>();

    // 道が壊れて行き来できない分の場合の数を引く
    for &(u, v) in &uv {
      let u = u - 1;
      let v = v - 1;
      next[u] -= dp[v];
      next[v] -= dp[u];
    }

    dp = next.iter().map(|v| v % m).collect::<Vec<_>>();
  }
  println!("{}", dp[0]);
}
