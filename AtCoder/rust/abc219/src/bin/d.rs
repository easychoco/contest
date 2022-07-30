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
    x: usize,
    y: usize,
    ab: [(usize, usize); n]
  }
  
  let inf = 1001001001;

  // dp[i][x][y] = i 個みて、 たこやき x 個 / たいやき y 個 のときの最小弁当個数
  let mut dp = vec![vec![vec![inf; 310]; 310]; 310];
  dp[0][0][0] = 0;
  for i in 0..n {
    let (a, b) = ab[i];
    for j in 0..=x {
      for k in 0..=y {
        dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);

        let nx = min(x, j + a);
        let ny = min(y, k + b);
        dp[i + 1][nx][ny] = min(dp[i + 1][nx][ny], dp[i][j][k] + 1);
      }
    }
  }

  let ans = if dp[n][x][y] == inf { -1 } else { dp[n][x][y] };
  println!("{}", ans);
}
