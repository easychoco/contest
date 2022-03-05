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
    mut p: [usize; n]
  }
  let mut ans = p
    .into_iter()
    .enumerate()
    .collect_vec();

  ans.sort_unstable_by_key(|val| val.1);
  for (idx, _) in ans {
    println!("{}", idx + 1);
  }    
}
