#[allow(unused_imports)]
use itertools::Itertools;
#[allow(unused_imports)]
use proconio::{fastout, input, marker::Chars};
#[allow(unused_imports)]
use std::cmp::{max, min};
#[allow(unused_imports)]
use std::collections::{BTreeSet, HashMap, HashSet, VecDeque};


// a^n % mod を計算する O(log n)
fn powmod(a: i64, n: i64, m: i64) -> i64 {
  // (a ^ n) % mを計算する
  let mut ret = 1;
  let mut a = a;
  let mut n = n;
  while n > 0 {
    if n % 2 == 1 { ret =  ret * a % m }
    a = a * a % m;
    n /= 2;
  }
  ret
}

// https://qiita.com/ngtkana/items/7d50ff180a4e5c294cb7
#[inline]
fn lsb(i: usize) -> usize {
    i & i.wrapping_neg()
}

struct Fenwick {
  table: Vec<i64>,
}
impl Fenwick {
  pub fn new(size: usize) -> Self {
      Self { table: vec![0; size] }
  }
  pub fn prefix_sum(&self, mut i: usize, m: i64) -> i64 {
    let mut res = 0;
    while i != 0 {
        res += self.table[i];
        res %= m;
        i -= lsb(i);
    }
    res
  }
  pub fn add(&mut self, mut i: usize, x: i64, m: i64) {
    i += 1;
    while i < self.table.len() {
        self.table[i] += x;
        self.table[i] %= m;
        i += lsb(i);
    }
  }
}

#[fastout]
fn main() {
  input! {
    n: usize,
    a: [i64; n]
  }

  let mut a = a
    .into_iter()
    .enumerate()
    .collect_vec();
  
  // val が等しい場合は idx の小さいものから見る必要があるので、 sort_unstable だと WA になる
  a.sort_by_key(|v| v.1);

  let m: i64 = 998244353;
  let inv2 = powmod(2, m - 2, m);

  let mut fw = Fenwick::new(n);
  let mut ans: i64 = 0;
  for (idx, _) in a.into_iter() {
    ans += (fw.prefix_sum(idx, m) * powmod(2, idx as i64, m)) % m;
    ans %= m;
    fw.add(idx, powmod(inv2, idx as i64 + 1, m), m);
  }
  println!("{}", ans);
}
