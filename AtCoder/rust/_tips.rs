// 座標圧縮
// let a = compress(a) の形で使う[]
// https://atcoder.jp/contests/abc213/tasks/abc213_c
fn compress(v: Vec<usize>) -> Vec<usize> {
  let mut v = v.into_iter().enumerate().collect_vec();
  v.sort_unstable_by_key(|val| val.1);
  
  let mut now = v[0].1;
  let mut val = 0_usize;
  for (_, x) in v.iter_mut() {
    if now != *x {
      now = *x;
      val += 1;
    }
    *x = val;
  }
  v.sort_unstable();
  v.into_iter().map(|(_, x)| x).collect_vec()
}
