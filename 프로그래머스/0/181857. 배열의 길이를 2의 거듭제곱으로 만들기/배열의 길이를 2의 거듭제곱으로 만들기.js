function solution(arr) {
    let minNum = 1024;
    
    for(let i = 0; i <= 10; i++){
        if(arr.length <= Math.pow(2, i)){
            minNum = Math.min(minNum, Math.pow(2, i) - arr.length);
        }
    }
    
    while(minNum--)
        arr.push(0);
    
    return arr;
}