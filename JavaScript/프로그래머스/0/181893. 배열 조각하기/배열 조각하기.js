function solution(arr, query) {
    query.forEach((v, i) => {
        if (i % 2) arr.splice(0, v);
        else arr.splice(v + 1);
    });
    
    return arr;
}