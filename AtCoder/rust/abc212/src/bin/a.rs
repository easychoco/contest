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
    a: usize,
    b: usize
  }

  let ans = if b == 0 {
    "Gold"
  } else if a == 0 {
    "Silver"
  } else {
    "Alloy"
  };
  println!("{}", ans);
}
