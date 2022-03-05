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
    l: usize,
    q: usize,
    query: [(usize, usize); q]
  }

  let mut st: BTreeSet<usize> = BTreeSet::new();
  st.insert(0);
  st.insert(l);
  for (c, x) in query {
    if c == 1 {
      st.insert(x);
    }
    else {
      let lower = st.range(..x).next_back().unwrap();
      let upper = st.range(x..).next().unwrap();
      println!("{}", upper - lower);
    }
  }
}
