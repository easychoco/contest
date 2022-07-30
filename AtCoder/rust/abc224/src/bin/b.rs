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
    h: usize,
    w: usize,
    a: [[usize; w]; h]
  }
  let mut ok = true;
  for y1 in 0..h {
    for y2 in y1 + 1..h {
      for x1 in 0..w {
        for x2 in x1 + 1..w {
          ok &= (a[y1][x1] + a[y2][x2] <= a[y1][x2] + a[y2][x1]);
        }
      }
    }
  }
  println!("{}", if ok { "Yes" } else { "No" });
}
