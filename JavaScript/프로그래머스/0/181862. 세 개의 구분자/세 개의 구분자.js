function solution(myStr) {
    let answer = myStr.split(/[a-c]/).filter(v => v);
    return answer.length > 0 ? answer : ["EMPTY"];
}