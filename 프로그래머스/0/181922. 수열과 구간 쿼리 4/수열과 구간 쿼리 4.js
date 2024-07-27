function solution(arr, queries) {
    for (let [s, e, k] of queries) {
        for (let i = s; i <= e; i++) {
            if (!(i % k)) arr[i]++;
        }
    }
    
    return arr;
}