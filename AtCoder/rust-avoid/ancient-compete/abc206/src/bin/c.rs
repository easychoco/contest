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
    a: [usize; n]
  }

  let mut mp = HashMap::<usize, i64>::new();
  for i in 0..n {
    *mp.entry(a[i]).or_insert(0) += 1;
  }
  let mut ans = n as i64 * (n + 1) as i64 / 2;
  for (_, v) in mp.into_iter() {
    ans -= v * (v + 1) / 2;
  }
  println!("{}", ans);
}
