#[allow(unused_imports)]
use itertools::Itertools;
#[allow(unused_imports)]
use proconio::{fastout, input, marker::Chars, marker::Usize1};
#[allow(unused_imports)]
use std::cmp::{max, min};
#[allow(unused_imports)]
use std::collections::{BTreeSet, HashMap, HashSet, VecDeque};

#[fastout]
fn main() {
  input! {
    n: usize,
    a: [Usize1; n]
  }

  let same_count = a
    .iter()
    .enumerate()
    .filter(|(index, &value)| *index == value)
    .count()
  ;

  let ans = same_count * (same_count - 1) / 2 +
    a.iter()
    .enumerate()
    .filter(|(i, &v)| a[v] == *i && v < *i)
    .count()
  ;
  
  println!("{}", ans);
}