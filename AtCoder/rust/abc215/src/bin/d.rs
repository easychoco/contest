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
    m: usize,
    mut a: [usize; n]
  }

  a.sort_unstable();
  a.dedup();

  let mut st = HashSet::new();
  for mut v in a.into_iter() {
    let mut p = 2;
    while p * p <= v {
      if v % p == 0 {
        st.insert(p);
      }
      while v % p == 0 {
        v /= p;
      }
      p += 1;
    }
    if v == 1 { continue; }
    st.insert(v);
  }
  
  let mut ans = vec![true; m + 1];
  for p in st {
    for i in 1..=m / p {
      ans[i * p] = false;
    }
  }

  let ans = ans
    .into_iter()
    .enumerate()
    .filter(|(_idx, val)| *val)
    .map(|(idx, _val)| idx)
    .collect_vec();

    println!("{}", ans.len() - 1);
  for v in ans.into_iter() {
    if v == 0 { continue }
    println!("{}", v);
  }
}
