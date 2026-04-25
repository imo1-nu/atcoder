use proconio::input;

fn main() {
    input! {
        n: usize,
        ab: [(usize, usize); n],
        m: usize,
        s: [String; m],
    }
    let a: Vec<usize> = ab.iter().map(|x| x.0).collect();
    let b: Vec<usize> = ab.iter().map(|x| x.1).collect();
}
