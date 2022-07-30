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
    n: usize
  }
  let val = n * 108 / 100;
  let ans = if val < 206 {
    "Yay!"
  } else if val == 206 {
    "so-so"
  } else {
    ":("
  };
  println!("{}", ans);

}
