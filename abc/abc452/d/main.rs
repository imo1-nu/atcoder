use proconio::input;

fn main() {
    input! {
        s: String,
        t: String,
    }

    let s: Vec<u8> = s.bytes().collect();
    let t: Vec<u8> = t.bytes().collect();
    let n = s.len();
    let m = t.len();

    let mut dp = vec![vec![-1i64; m + 1]; n];
    for i in 0..n {
        dp[i][0] = i as i64;
    }

    for i in 0..n {
        if i > 0 {
            for j in 1..=m {
                dp[i][j] = dp[i - 1][j];
            }
        }

        for j in (0..m).rev() {
            if s[i] == t[j] {
                dp[i][j + 1] = dp[i][j];
            }
        }
    }

    let ans: i64 = (0..n).map(|i| i as i64 - dp[i][m]).sum();
    println!("{}", ans);
}