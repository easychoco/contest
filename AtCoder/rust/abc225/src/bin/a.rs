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
    mut s: Chars
  }
  s.sort();
  let f1 = s[0] == s[1];
  let f2 = s[1] == s[2];
  if f1 && f2 {
    println!("1");
  }
  else if f1 || f2 {
    println!("3");
  }
  else {
    println!("6");
  }
}
