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
    k: u32,
    a: String,
    b: String
  }
  let ans = i64::from_str_radix(&a, k).unwrap() * i64::from_str_radix(&b, k).unwrap();
  println!("{}", ans);
}
