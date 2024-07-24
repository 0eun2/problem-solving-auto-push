function solution(a, b) {
    var answer = 0;
    let num1 = Number(a.toString() + b.toString());
    let num2 = Number(b.toString() + a.toString());
        
    if(num1 >= num2) answer = num1;
    else answer = num2;
    
    return answer;
}