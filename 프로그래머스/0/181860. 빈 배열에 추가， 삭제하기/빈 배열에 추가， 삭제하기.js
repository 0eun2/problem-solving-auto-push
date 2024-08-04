function solution(arr, flag) {
    var answer = [];
    
    arr.forEach((v, i) =>{
       if (flag[i]) {
           for (let i = 0; i < v * 2; i++)
               answer.push(v);
       } else {
           for (let i = 0; i < v; i++) {
               answer.pop();
           }
       }
    });
    
    return answer;
}