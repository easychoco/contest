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
    a: i32,
    b: i32,
    c: i32
  }
  let val = b / c * c;
  let ans = if val < a { -1 } else { val };
  println!("{}", ans);
}
