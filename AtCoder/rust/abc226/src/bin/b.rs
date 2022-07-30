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
  let mut st = HashSet::<Vec<usize>>::new();
  for _ in 0..n {
    input! {
      l: usize,
      a: [usize; l]
    }
    st.insert(a);
  }
  println!("{}", st.len());
}
