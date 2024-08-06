function solution(picture, k) {
    var answer = [];
    
    picture = picture.map(v => [...v].map(c => c.repeat(k)).join(''));
    picture.forEach(v => answer = [...answer, ...new Array(k).fill(v)]);
    
    return answer;
}