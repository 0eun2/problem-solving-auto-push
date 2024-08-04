function solution(arr) {
    return +arr.every((r, i) => r.every(($, j) => arr[i][j] === arr[j][i]));
}