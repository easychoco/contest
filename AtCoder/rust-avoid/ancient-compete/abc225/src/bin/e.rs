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
  let mut rad = vec![];
  for (x, y) in xy.into_iter() {
    let x1 = x - 1;
    let y1 = y;

    let x2 = x;
    let y2 = y - 1;

    rad.push( (y1, x1, y2, x2) );
  }

  // ay1/ax1 < by1/bx1
  rad.sort_by(|(ay1, ax1, ay2, ax2), (by1, bx1, by2, bx2)| {
      if ay1*bx1 == by1*ax1 { (ay2*bx2).cmp(&(by2*ax2)) } else { (ay1*bx1).cmp(&(by1*ax1)) }
    }
  );

  let mut now = 0;
  let mut ans = 1;
  for i in 1..n {
    let (_ay1, _ax1, ay2, ax2) = rad[i];
    let (by1, bx1, _by2, _bx2) = rad[now];

    // now_to < i_from
    // by1/bx1 < ay2/ax2
    if by1*ax2 <= bx1*ay2 {
      now = i;
      ans += 1;
    }
  }
  println!("{}", ans);
}
