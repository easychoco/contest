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
    n: usize,
    x: usize,
    a: [usize; n]
  }

  let sum = a.iter().sum::<usize>() - n / 2;
  let ans = if sum <= x { "Yes" } else { "No" };
  println!("{}", ans);
}
