
use std::io;
use std::collections::HashMap;
fn main(){
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read line");

    let mut sum: i32 = 0;
    // split the string and add up sum
    for c in input.trim().chars(){
        let digit = c as i32 - '0' as i32;
        sum += digit;
    }
    let mut pinyin_map = HashMap::new();
    pinyin_map.insert('0', "ling");
    pinyin_map.insert('1', "yi");
    pinyin_map.insert('2', "er");
    pinyin_map.insert('3', "san");
    pinyin_map.insert('4', "si");
    pinyin_map.insert('5', "wu");
    pinyin_map.insert('6', "liu");
    pinyin_map.insert('7', "qi");
    pinyin_map.insert('8', "ba");
    pinyin_map.insert('9', "jiu");
    // println!("sum = {}", sum);
    let mut first = true;
    for c in sum.to_string().chars() {
        if let Some(pinyin) = pinyin_map.get(&c) {
            if first{
                print!("{}", pinyin);
                first = false;
            }else{
                print!(" {}", pinyin);
            }
        }
    }
    println!("");
}