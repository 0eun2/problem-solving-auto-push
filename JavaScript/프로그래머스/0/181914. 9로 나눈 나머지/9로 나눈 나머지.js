function solution(number) {
    var answer = 0;
    
    for (let i of number) {
        answer += Number(i);
    }
    
    return answer % 9;
}