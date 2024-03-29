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
    let n = read_one_num();
    let nums = read_one_line();
    let k = read_one_num();
    let mut i:usize = 0;
    while i < (k as usize){
        let nums2 = read_one_line();
        let mut wrong = 0;
        let mut right = 0;
        let mut _give_up = 0;
        let mut j:usize = 0;
        
        while j < (n as usize){
            // println!("i = {}, j ={}", i, j);
            if nums2[j] == 0{
                _give_up += 1;
            }else if nums[j] == nums2[j]{
                right += 1;
            }else{
                wrong += 1;
                break;
            }
            j+=1; 
        }
        if wrong == 0 && right > 0{
            println!("Da Jiang!!!");
        }else {
            println!("Ai Ya");
        }
        i+=1;  
    }
}