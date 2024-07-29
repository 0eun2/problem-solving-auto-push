function solution(my_string) {
    var answer = new Array(52).fill(0);
    
    for (let v of my_string) {
        if (v.toUpperCase() === v){
            answer[v.charCodeAt() - 'A'.charCodeAt()]++; 
        } else {
            answer[v.charCodeAt() - 'a'.charCodeAt() + 26]++; 
        }
    }
    
    return answer;
}