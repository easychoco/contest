use proconio::input;

fn main() {
  input! {
    mut a: i64,
    mut b: i64,
    mut c: i64
  }
  if c % 2 == 0 {
    a = a * a;
    b = b * b;
  };
  if a < b {
    println!("<");
  }
  else if a == b {
    println!("=");
  }
  else {
    println!(">");
  }
}

