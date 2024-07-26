function solution(arr, queries) {
    var answer = [];
    
    for(let [s, e, k] of queries){
        let arr2 = arr.slice(s, e + 1).filter((value) => value > k);
        answer.push(arr2.length > 0 ? Math.min(...arr2) : -1);
    }
    
    return answer;
}