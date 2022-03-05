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
    ab: [(f64, f64); n]
  }
  let all_time: f64 = ab.iter().map(|(a, b)| a / b).sum();
  let mut length = 0.0;
  let mut time = 0.0;
  for (a, b) in ab.into_iter() {
    if time + a / b < all_time / 2.0 {
      length += a;
      time += a / b;
    } else {
      let res = all_time / 2.0 - time;
      length += res * b;
      break;
    }
  }
  println!("{}", length);
}
