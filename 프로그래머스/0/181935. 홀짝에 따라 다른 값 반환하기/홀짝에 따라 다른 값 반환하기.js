function solution(n) {
    var answer = 0;
    
    if(n % 2){  // 홀수
        while(n > 0){
            answer += n;
            n -= 2;
        }
    } else {    // 짝수
        while(n > 0){
            answer += n ** 2;
            n -= 2;
        }
    }
    
    return answer;
}