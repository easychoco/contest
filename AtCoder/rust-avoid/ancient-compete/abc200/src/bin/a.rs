use proconio::input;

fn main() {
    input! {
      n: i64
    }
    println!("{}", (n - 1) / 100 + 1);
}
