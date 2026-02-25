use std::io;
pub fn read_one_line()->Vec<String>{
    let mut input = String::new();

    io::stdin().read_line(&mut input)
        .expect("Failed to read line");

        let parts: Vec<String> = input.split_whitespace().map(|s| s.to_string()).collect();
    return parts;
}
fn main(){
    let u = read_one_line();
    let n:i32 = u[0].parse().expect("Failed to parse number");
    let v:i32 = u[1].parse().expect("Failed to parse number");
    let t = n + v;
    let mut total = 1;
    for i in 1..=t{
        total = total*i;
    }
    println!("{}", total);
}

