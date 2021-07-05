use proconio::input;

fn main() {
  input! {
    n: usize,
    mut a: [usize; n]
  }
  a.sort();
  a.dedup();
  if a.len() == n && a[n - 1] == n {
    println!("Yes");    
  } else {
    println!("No");
  }
}

