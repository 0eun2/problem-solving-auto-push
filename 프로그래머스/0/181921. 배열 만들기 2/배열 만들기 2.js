function solution(l, r) {
    var answer = [];
    
    for (let i = l; i <= r; i++) {
        let included = true;
        
        for (let j of String(i)) {
            if (j !== '0' && j !== '5') {
                included = false;
                break;
            }
        }
        
        if(included) answer.push(i);
    }
    
    return answer.length > 0 ? answer : [-1];
}