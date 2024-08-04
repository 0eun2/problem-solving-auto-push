function solution(strArr) {
    let cnt = new Array(30).fill(0);
    
    strArr.forEach(v => cnt[v.length - 1]++);
    
    return Math.max(...cnt);
}