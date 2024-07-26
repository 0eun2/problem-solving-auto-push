function solution(code) {
    var answer = '';
    let mode = 0;
    
    for (let idx = 0; idx < code.length; idx++){
        if (code[idx] === '1')
            mode = !mode;
        else if((!mode && !(idx % 2)) || (mode && idx % 2))
            answer += code[idx];
    }
    
    if (answer === '') return "EMPTY"
    return answer;
}