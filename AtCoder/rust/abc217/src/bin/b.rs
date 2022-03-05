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
    s: [String; 3]
  }
  let contests = vec!["ABC", "ARC", "AGC", "AHC"];
  for c in contests {
    if !s.contains(&c.to_string()) {
      println!("{}", c);
    }
  }
}
