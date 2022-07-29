#[allow(unused_imports)]
use proconio::{input, fastout, marker::Chars};
#[allow(unused_imports)]
use std::collections::{HashSet, HashMap, BTreeSet, VecDeque};
#[allow(unused_imports)]
use std::cmp::{max, min};
#[allow(unused_imports)]
use itertools::Itertools;

#[fastout]
fn main() {
  input! {
    s: Chars
  }
  let m = 1000000007;
  let base = "chokudai";
  let mut dp = vec![0_i32; 8];
  for c in s {
    for (i, bc) in base.chars().enumerate() {
      if c == bc {
        if i == 0 {
          dp[0] += 1;
          dp[0] %= m;
        } else {
          dp[i] += dp[i - 1];
          dp[i] %= m;
        }
      }
    }
  }
  println!("{}", dp[7]);
}
