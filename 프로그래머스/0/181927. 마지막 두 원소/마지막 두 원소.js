function solution(num_list) {
    let num = 0;
    
    if (num_list[num_list.length - 1] > num_list[num_list.length - 2]) {
        num = num_list[num_list.length - 1] - num_list[num_list.length - 2];
    } else {
        num = num_list[num_list.length - 1] * 2;
    }
    
    num_list.push(num);
    
    return num_list;
}