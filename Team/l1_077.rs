use std::io;
fn main(){
    let mut input = String::new();

    // 从标准输入中读取一行，并将结果存储到 input 变量中
    io::stdin().read_line(&mut input)
        .expect("Failed to read line");

    // 使用 split_whitespace 方法将字符串拆分为单独的数字
    let numbers: Vec<i32> = input
        .split_whitespace()
        .filter_map(|s| s.trim().parse().ok())
        .collect();
    loop{
        let mut input2 = String::new();
        io::stdin().read_line(&mut input2)
        .expect("Failed to read line");
        let num: i32 = match input2.trim().parse() {
            Ok(num) => num,
            Err(_) => {
                println!("Invalid input. Please enter an integer.");
                return;
            }
        };
        if num < 0 || num > 23{
            break;
        }
        let t = numbers[num as usize];
        if t > 50 {
            println!("{} Yes", t);
        }else{
            println!("{} No", t);
        }
    }
    
    
}