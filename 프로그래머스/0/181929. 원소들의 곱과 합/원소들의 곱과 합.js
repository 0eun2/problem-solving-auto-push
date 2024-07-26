function solution(num_list) {
    return num_list.reduce((acc, cur) => acc * cur) 
            < Math.pow(num_list.reduce((acc, cur) => acc + cur), 2) ? 1 : 0;
}