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
    n: usize,
    mut a: [usize; n]
  }
  let a = a.into_iter()
           .enumerate()
           .sorted_by_key(|x| x.1)
           .collect_vec();
  println!("{}", a[n - 2].0 + 1);
}
