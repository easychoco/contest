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
    st: [(String, String); n]
  }
  let mut st = st
    .into_iter()
    .map(|(s, t)| s + " " + &t)
    .collect_vec();
    
  st.sort_unstable();
  st.dedup();

  let ans = if st.len() == n { "No" } else { "Yes" };
  println!("{}", ans);
}
