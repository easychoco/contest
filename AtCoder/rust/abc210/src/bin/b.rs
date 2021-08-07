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
    _n: usize,
    s: String
  }
  let idx = s.find('1').unwrap();
  let ans = if idx % 2 == 0 { "Takahashi" } else { "Aoki" };
  println!("{}", ans);
}
