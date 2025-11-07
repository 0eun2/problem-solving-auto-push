function solution(arr) {
    if (arr.length > arr[0].length) {
        for (let i = 0; i < arr.length; i++) {
            while (arr.length !== arr[i].length)
                arr[i].push(0);
        }
    } else if (arr.length < arr[0].length) {
        for (let i = arr.length; i < arr[0].length; i++) {
            arr.push(new Array(arr[0].length).fill(0));
        }
    }
    
    return arr;
}