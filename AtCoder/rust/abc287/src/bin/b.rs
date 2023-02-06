#[allow(unused_imports)]
use itertools::Itertools;
#[allow(unused_imports)]
use proconio::{fastout, input, marker::Chars, marker::Usize1};
#[allow(unused_imports)]
use std::cmp::{max, min};
#[allow(unused_imports)]
use std::collections::{BTreeSet, HashMap, HashSet, VecDeque};

#[fastout]
fn main() {
  input! {
    n: isize,
    m: isize,
    s: [Chars; n],
    t: [Chars; m],
  }

  let mut ans = 0;
  for s_i in s {
    for t_i in &t {
      if s_i[3..6] == t_i[0..] {
        ans += 1;
        break;
      }
    }
  }
  println!("{}", ans);
}
