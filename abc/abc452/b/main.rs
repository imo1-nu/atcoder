use proconio::input;

fn main() {
    input! {
        h: usize,
        w: usize,
    }
    
    let top = "#".repeat(w);
    let mid = format!("#{}#", ".".repeat(w - 2));

    println!("{}", top);
    for _ in 0..h - 2 {
        println!("{}", mid);
    }
    println!("{}", top);
}
