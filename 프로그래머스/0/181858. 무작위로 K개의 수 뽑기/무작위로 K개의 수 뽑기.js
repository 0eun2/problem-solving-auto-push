function solution(arr, k) {
    let set = new Set(arr);
    arr = [...set];
    
    if (arr.length > k) {
        while (arr.length !== k)
            arr.pop();
    } else {
        while (arr.length !== k)
            arr.push(-1);
    }
    
    return arr;
}