function solution(myString, pat) {
    var answer = 0;
    let pos = -1;
    
    while (true) {
        pos = myString.indexOf(pat, pos + 1);
        
        if (pos === -1) break;
        
        answer++;
    }
    
    return answer;
}