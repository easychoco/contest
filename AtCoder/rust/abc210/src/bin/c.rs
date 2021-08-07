#[allow(unused_imports)]
use proconio::{input, fastout, marker::Chars};
#[allow(unused_imports)]
use std::collections::{HashSet, HashMap, BTreeSet, VecDeque};
#[allow(unused_imports)]
use std::cmp::{max, min};
#[allow(unused_imports)]
use itertools::Itertools;

#[fastout]
fn main() {
  input! {
    n: usize,
    k: usize,
    c: [usize; n]
  }

  let mut mp: HashMap<usize, usize> = HashMap::new();

  // 先頭から k 個のキャンディをもらう
  for i in 0..k {
    *mp.entry(c[i]).or_insert(0) += 1;
  }

  // len() がいま持っているキャンディの種類になる
  let mut ans = mp.len();

  // 残りのキャンディについて処理する
  for i in k..n {
    // i を加えて、 i-k を引く
    *mp.entry(c[i]).or_insert(0) += 1;
    *mp.entry(c[i - k]).or_insert(0) -= 1;

    // いま持っているキャンディの種類を len() で表すので、個数が 0 になったものは取り除く
    if mp[&c[i - k]] == 0 {
      mp.remove(&c[i - k]);
    }

    // 答えを更新
    ans = max(ans, mp.len());
  }
  println!("{}", ans);
}
