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
    mut x: i64,
    mut y: i64,
    a: i64,
    b: i64,
    c: i64
  }

  // check(面積1, 面積2, 面積3, 横, 縦) = この条件で敷き詰めることができるか
  let check = |a: i64, b: i64, c: i64, x: i64, y: i64| -> bool {
    let mut tx = x;
    let mut ret = false;

    // a を辺いっぱいに配置する
    tx -= (a - 1) / y + 1;

    // b, c を横に配置する
    if tx > 0 {
      let mut ty = y;
      ty -= (b - 1) / tx + 1;
      ty -= (c - 1) / tx + 1;
      ret |= ty >= 0;
    }

    // b, c を縦に配置する
    tx -= (b - 1) / y + 1;
    tx -= (c - 1) / y + 1;
    ret |= tx >= 0;

    ret
  };

  let mut ans = false;
  ans |= check(a, b, c, x, y); // a先頭, x横, y縦
  ans |= check(b, c, a, x, y); // b先頭, x横, y縦
  ans |= check(c, a, b, x, y); // c先頭, x横, y縦

  ans |= check(a, b, c, y, x); // a先頭, y横, x縦
  ans |= check(b, c, a, y, x); // b先頭, y横, x縦
  ans |= check(c, a, b, y, x); // c先頭, y横, x縦

  println!("{}", if ans { "Yes" } else { "No" });
}
