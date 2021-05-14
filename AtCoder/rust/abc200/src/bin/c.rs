use proconio::input;

fn main() {
    input! {
      n: i64,
      a: [i64; n]
    }
    let mut v: Vec<i64> = vec![0; 200];
    for a in a {
        v[(a % 200) as usize] += 1;
    }
    let mut ans: i64 = 0;
    for i in 0..200 {
        ans += v[i] * (v[i] - 1) / 2;
    }
    println!("{}", ans);
}
