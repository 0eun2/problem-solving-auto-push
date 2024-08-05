function solution(arr) {
    var answer = [];
    
    arr.forEach(v => {
        if (answer[answer.length - 1] === v) answer.pop();
        else answer.push(v);
    })
    
    return answer.length ? answer : [-1];
}