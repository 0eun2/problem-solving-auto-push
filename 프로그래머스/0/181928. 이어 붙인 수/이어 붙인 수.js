function solution(num_list) {
    let odd = Number(num_list.filter((num) => num % 2).join(''));
    let even = Number(num_list.filter((num) => !(num % 2)).join(''));
    return odd + even; 
}