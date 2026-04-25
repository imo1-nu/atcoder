use proconio::input;

fn main() {
    input! {
        m: i32,
        d: i64,
    }
    let result = match (m, d) {
        (1, 7) | (3, 3) | (5, 5) | (7, 7) | (9, 9) => "Yes",
        _ => "No",
    };
    println!("{}", result);
}
