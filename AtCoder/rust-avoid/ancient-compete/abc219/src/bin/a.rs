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
    x: usize
  }

  if 90 <= x {
    println!("expert");
    return;
  }

  let ans = if x < 40 { 40 - x }
    else if x < 70 { 70 - x }
    else { 90 - x };

  println!("{}", ans);

}
