function solution(arr, n) {
    return arr.length % 2 ? arr.map((v, i) => i % 2 ? v : v + n) : arr.map((v, i) => i % 2 ? v + n : v);
}