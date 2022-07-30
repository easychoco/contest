#[allow(unused_imports)]
use itertools::Itertools;
#[allow(unused_imports)]
use proconio::{fastout, input, marker::Chars};
#[allow(unused_imports)]
use std::cmp::{max, min};
#[allow(unused_imports)]
use std::collections::{BTreeSet, HashMap, HashSet, VecDeque};
use num::abs;

#[fastout]
fn main() {
  input! {
    n: usize,
    m: usize,
    mut a: [i32; n],
    mut b: [i32; m],
  }

  a.sort();
  b.sort();

  let mut i = 0;
  let mut ans = 2100100100;
  for v in a {
    while i < m && b[i] <= v {
      ans = min(ans, abs(v - b[i]));
      i += 1;
    }
    if i < m {
      ans = min(ans, abs(v - b[i]));
    } else {
      break;
    }
  }
  println!("{}", ans);
}
