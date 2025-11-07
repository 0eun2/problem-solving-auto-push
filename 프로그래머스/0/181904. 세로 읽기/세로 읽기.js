function solution(my_string, m, c) {
    let arr = [];
    
    for (let i = 0 ; i < my_string.length; i += m){
        arr.push(my_string.substr(i, m));
    }
    
    return arr.map((_, i) => arr[i][c - 1]).join('');
}