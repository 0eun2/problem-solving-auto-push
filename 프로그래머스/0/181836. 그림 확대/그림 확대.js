function solution(picture, k) {
    var answer = [];
    
    picture.map(v => {
        const cur = [...v].map(c => c.repeat(k)).join('');
        for (let i = 0; i < k; i ++) answer.push(cur);
    });
    
    return answer;
}