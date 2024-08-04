function solution(arr, delete_list) {
    var answer = [];
    
    arr.forEach(v => {
        if(!delete_list.includes(v)) answer.push(v)
    });
    
    return answer;
}