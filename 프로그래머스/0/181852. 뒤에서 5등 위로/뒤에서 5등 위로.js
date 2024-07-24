function solution(num_list) {
    let cnt = 5;
    
    num_list.sort((a, b) => a - b);
    
    while(cnt--){
        num_list.shift();
    }
    
    return num_list;
}