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
    mut s: Chars,
    t: Chars
  }

  if s == t {
    println!("Yes");
    return;
  }

  for i in 0..s.len() - 1 {
    s.swap(i, i + 1);
    if s == t {
      println!("Yes");
      return;
    }
    s.swap(i, i + 1);
  }
  println!("No");
}
