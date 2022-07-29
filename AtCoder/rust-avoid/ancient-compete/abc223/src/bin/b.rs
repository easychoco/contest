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
    s: String
  }
  let mut pool = vec![];
  for i in 0..s.len() {
    let nx = s[i..].to_string() + &s[0..i];
    pool.push(nx);
  }
  pool.sort_unstable();
  println!("{}", pool[0]);
  println!("{}", pool.pop().unwrap());
}
