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
    ab: [(usize, usize); m]
  }

  let m: i64 = 998244353;
  let sz = n * 2;
  // comb[n][k] = n から ｋ とる組み合わせ () n C k ) の値
  let mut comb = vec![vec![0_i64; sz + 1]; sz + 1];
  comb[0][0] = 1;
  for i in 1..sz {
    comb[i][0] = 1;
    comb[i][i] = 1;
    for j in 0..i - 1 {
      comb[i][j + 1] = comb[i - 1][j] + comb[i - 1][j + 1];
      comb[i][j + 1] %= m;
    }
  }

  // dp[l][r] = 区間 [l, r] の組み合わせ
  let mut dp = vec![vec![0_i64; sz]; sz];
  let mut ok = vec![vec![false; sz]; sz];
  for (a, b) in ab {
    let (a, b) = (a - 1, b - 1);
    ok[a][b] = true;
  }

  for pair in 1..=n { // つくるペアの個数
    for left in 0..sz { // 左端のインデックス
      let right = left + pair * 2 - 1; // 右端のインデックス
      if right >= sz { break; } // 範囲外で break
      for i in 0..pair {
        let pi = left + i * 2 + 1; // left とペアにするインデックス
        if !ok[left][pi] { continue; } // ペアになれなければ continue

        let l = if left + 1 < pi - 1 { dp[left + 1][pi - 1] } else { 1 }; // pi の左側のペア数
        let r = if pi + 1 < right { dp[pi + 1][right] } else { 1 }; // pi の右側のペア数
        let perm = l * r % m;
        dp[left][right] += perm * comb[pair][i + 1]; // [left][iペア][pi][pair - i - 1 ペア]
        dp[left][right] %= m;
      }
    }
  }
  println!("{}", dp[0][sz - 1]);
}
