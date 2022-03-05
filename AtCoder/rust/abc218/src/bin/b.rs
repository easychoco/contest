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
    p: [usize; 26]
  }
  let ans = p
    .into_iter()
    .map(|p| (p - 1) + 'a' as usize)
    .map(|p| p as u8 as char)
    .join("");
  println!("{}", ans);
}
