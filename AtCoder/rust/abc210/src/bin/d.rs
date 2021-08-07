#[allow(unused_imports)]
use proconio::{input, fastout, marker::Chars};
#[allow(unused_imports)]
use std::collections::{HashSet, HashMap, BTreeSet, VecDeque};
#[allow(unused_imports)]
use std::cmp::{max, min};
#[allow(unused_imports)]
use itertools::Itertools;

use std::mem;

#[fastout]
fn main() {
  input! {
    h: usize,
    w: usize,
    c: u64,
    mut a: [[u64; w]; h]
  }

  let inf: u64 = 1_000_000_000_000_000_000;
  let mut ans = inf;
  
  for _ in 0..2 { 
       
    // どこかに駅を立てて dp[y][x] にいるときの最小コスト
    let mut dp = vec![vec![inf; w]; h];
    // dp[y][x] + a[y][x] が (y, x) に2つめの駅を立てた時のコストになる
    // この dp[y][x] + a[y][x] を最小化する
    
    // 移動方向を固定することで、絶対値を外して考えられる
    for y in 0..h {
      for x in 0..w {
        if y > 0 && x > 0 {
          dp[y][x] = min(
              min(dp[y - 1][x], dp[y][x - 1]),
              min( a[y - 1][x],  a[y][x - 1])
            ) + c;
        }
        else if y > 0 { // x == 0 のとき
          dp[y][x] = min(dp[y - 1][x], a[y - 1][x]) + c;
        }
        else if x > 0 { // y == 0 のとき
          dp[y][x] = min(dp[y][x - 1], a[y][x - 1]) + c;
        }
        ans = min(ans, dp[y][x] + a[y][x]);
      }
    }

    // 上下反転
    for y in 0..h / 2 {
      let (v1, v2) =  a.split_at_mut(h - y - 1);
      mem::swap(&mut v1[y], &mut v2[0]);
    }
  }
  println!("{}", ans);
}
