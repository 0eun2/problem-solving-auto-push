function solution(arr1, arr2) {
    if (arr1.length !== arr2.length) return arr1.length > arr2.length ? 1 : -1;
    else {
        let sum1 = arr1.reduce((acc, cur) => acc + cur, 0);
        let sum2 = arr2.reduce((acc, cur) => acc + cur, 0);
        
        if (sum1 === sum2) return 0;
        else return sum1 > sum2 ? 1 : -1;
    }
}