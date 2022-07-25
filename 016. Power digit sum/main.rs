extern crate num;

use num::BigUint;
use num::pow::pow;

/*
*   2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
*   
*   What is the sum of the digits of the number 2^1000?
*   
*   Answer: 1366
*/

fn main() {
    println!("{}", pow(BigUint::from(2u32), 1000).to_string().chars().map(|ch| ch.to_digit(10).unwrap()).sum::<u32>());
}   

