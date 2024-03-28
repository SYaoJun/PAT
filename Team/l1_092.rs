// 3
// 3 3 9
// 3 3 6
// 3 3 12

use std::io;
pub fn read_one_num()->i32{
    let mut input2 = String::new();
        io::stdin().read_line(&mut input2)
        .expect("Failed to read line");
        let num: i32 = match input2.trim().parse() {
            Ok(num) => num,
            Err(_) => {
                println!("Invalid input. Please enter an integer.");
                return 0;
            }
        };
        return num;
}
pub fn read_one_line()->Vec<i32>{
    let mut input = String::new();

    io::stdin().read_line(&mut input)
        .expect("Failed to read line");

    let numbers: Vec<i32> = input
        .split_whitespace()
        .filter_map(|s| s.trim().parse().ok())
        .collect();
    return numbers;
}
fn main(){
    let a = read_one_num();
    
    let mut i = 0;
    while i < a{
        let b = read_one_line();
        if b[0] * b[1] == b[2]{
            println!("Lv Yan");
        }else if b[0] + b[1] == b[2]{
            println!("Tu Dou");
        }else{
            println!("zhe du shi sha ya!");
        }
        i+=1;
    }
}