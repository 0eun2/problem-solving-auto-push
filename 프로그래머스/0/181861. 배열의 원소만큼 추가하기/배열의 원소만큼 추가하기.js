function solution(arr) {
    var answer = [];
    
    arr.forEach((x) => {
        for ( let i = 0; i < x; i ++) answer.push(x);
    });
    
    return answer;
}