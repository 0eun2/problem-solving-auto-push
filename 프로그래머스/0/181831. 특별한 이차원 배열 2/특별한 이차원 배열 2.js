function solution(arr) {
    return +arr.every((_, i) => arr.every(($, j) => arr[i][j] === arr[j][i]));
}