#[allow(unused_imports)]
use proconio::{input, fastout, marker::Chars};
#[allow(unused_imports)]
use std::collections::{HashSet, HashMap, BTreeSet, VecDeque};
#[allow(unused_imports)]
use std::cmp::{max, min};
#[allow(unused_imports)]
use itertools::Itertools;

fn fact(n: usize) -> usize {
  if n <= 1 { 
    1 
  } else { 
    n * fact(n - 1)
  }
}

#[fastout]
fn main() {
  input! {
    mut p: usize
  }

  // 大きい硬貨から
  let mut ans = 0;
  for i in (1..=10).rev() {
    let mut coin = fact(i);
    // いまの硬貨で払えるだけ払う
    ans += p / coin;
    // 残り金額が p % coin になる
    p %= coin;
  }
  println!("{}", ans);
}
