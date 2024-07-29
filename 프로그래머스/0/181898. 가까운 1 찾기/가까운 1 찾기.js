function solution(arr, idx) {    
    for (let i = idx; i < arr.length; i++) {
        if (arr[i]) return i;
    }
    
    return -1;
}