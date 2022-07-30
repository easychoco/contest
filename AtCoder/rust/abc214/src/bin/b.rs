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
    s: usize,
    t: usize
  }
  let mut ans = 0;
  for a in 0..=s {
    for b in 0..=s {
      for c in 0..=s {
        if a + b + c > s { break; }
        if a * b * c <= t { ans += 1; } 
      }
    }
  }
  println!("{}", ans);
}
