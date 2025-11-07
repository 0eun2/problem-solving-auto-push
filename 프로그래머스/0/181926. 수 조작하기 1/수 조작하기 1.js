function solution(n, control) {
    const controlValue = {
        'w' : 1,
        's' : -1,
        'd' : 10,
        'a' : -10,
    }
    
    for(let i of control){
        n += controlValue[i];
    }
    
    return n;
}