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
  let l = a;
  let r = a * 6;
  let ans = if (l..=r).contains(&b) { "Yes" } else { "No" };
  println!("{}", ans);
}
