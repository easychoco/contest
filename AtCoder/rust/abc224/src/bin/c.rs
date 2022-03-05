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
    xy: [(i64, i64); n]
  }
  let mut ans = 0;
  for i1 in 0..n {
    for i2 in i1 + 1..n {
      for i3 in i2 + 1 ..n {
        let xy1 = xy[i1];
        let xy2 = xy[i2];
        let xy3 = xy[i3];

        // (xy1.1 - xy2.1) / (xy1.0 - xy2.0) == (xy1.1 - xy3.1) / (xy1.0 - xy3.0)
        let ok = (xy1.1 - xy2.1) * (xy1.0 - xy3.0) != (xy1.1 - xy3.1) * (xy1.0 - xy2.0);
        if ok {
          ans += 1;
        }
      }
    }
  }
  println!("{}", ans);
}
