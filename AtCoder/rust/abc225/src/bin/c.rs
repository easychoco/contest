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
    mut b: [[i64; m]; n]
  }

  let mut ok = true;
  for y in 0..n - 1 {
    for x in 0..m {
      ok &= (b[y][x] + 7 == b[y + 1][x]);
    }
  }

  for y in 0..n - 1 {
    for x in 0..m {
      b[y][x] -= 1;
    }
  }

  for x in 0..m - 1 {
    ok &= (b[0][x] + 1 == b[0][x + 1]) && (b[0][x] % 7 < b[0][x + 1] % 7);
  }

  println!("{}", if ok { "Yes" } else { "No" });
}
