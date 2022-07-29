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
    n: i64,
    k: i64,
    a: [i64; n],
  }

  // arg 以上の要素の個数が k 個以上あるかどうか
  let f = |arg: i64| -> bool {
    let cnt: i64 = a
      .iter()
      .map(|a| max(0, *a as i64 - arg + 1))
      .sum();
    return cnt >= k as i64;
  };

  let mut ac: i64 = 0;
  let mut wa: i64 = 1001001001001;
  while wa - ac > 1 {
    let wj: i64 = (wa + ac) / 2;
    if f(wj) { ac = wj; } else { wa = wj; }
  }

  let mut ans: i64 = 0;
  let mut cnt: i64 = 0;
  for a in a.into_iter() {
    let diff = max(0, a - wa + 1);
    ans += diff * (2 * wa + diff - 1) / 2;
    cnt += diff;
  }
  ans += (k - cnt) * ac as i64;
  println!("{}", ans);
}
