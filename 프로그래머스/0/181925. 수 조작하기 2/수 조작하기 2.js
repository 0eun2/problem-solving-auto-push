function solution(numLog) {
    var answer = '';
    const control = {
        'w': 1,
        's': -1,
        'd': 10,
        'a': -10
    }
    
    for (let i = 1; i < numLog.length; i++) {
        answer += Object.keys(control).find(key => control[key] === numLog[i] - numLog[i - 1]);
    }
    
    return answer;
}