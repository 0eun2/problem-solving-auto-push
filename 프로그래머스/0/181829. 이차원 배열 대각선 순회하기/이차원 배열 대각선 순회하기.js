function solution(board, k) {
    console.log(board.filter((b, i) => i === i));
    return board.map((b, i) => b.filter((_, j) => i + j <= k)).reduce((a, c) => [...a, ...c], []).reduce((a, c) => a + c);
}