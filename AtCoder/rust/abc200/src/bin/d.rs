use core::cmp;
use proconio::input;

fn main() {
    input! {
      n: i32,
      mut a: [i32; n]
    }
    for i in &mut a {
        *i %= 200;
    }
    let mut v: Vec<Vec<i32>> = vec![vec![]; 200];
    let sz = cmp::min(8, n);
    for bit in 0..1 << sz {
        let mut idx: Vec<i32> = vec![];
        let mut sum: i32 = 0;
        for i in 0..sz {
            if (bit >> i & 1) > 0 {
                sum += a[i as usize];
                idx.push(i);
                sum %= 200;
            }
        }
        if v[sum as usize].len() > 0 {
            println!("Yes");
            println!(
                "{} {}",
                v[sum as usize].len(),
                v[sum as usize]
                    .iter()
                    .map(|x| (x + 1).to_string())
                    .collect::<Vec<_>>()
                    .join(" ")
            );
            print!(
                "{} {}",
                idx.len(),
                idx.iter()
                    .map(|x| (x + 1).to_string())
                    .collect::<Vec<_>>()
                    .join(" ")
            );
            return;
        }
        v[sum as usize] = idx;
    }
    println!("No");
}
