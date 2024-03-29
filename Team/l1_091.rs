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
    let x = &u[1];
    let m:i32 = u[2].parse().expect("Failed to parse number");
    let k:i32 = u[3].parse().expect("Failed to parse number");
    if k == n{
        println!("mei you mai {} de", x);
    }else if k == m{
        println!("kan dao le mai {} de", x);
    }else{
        println!("wang le zhao mai {} de", x);
    }
}