function solution(rank, attendance) {
    let possible = rank.filter((_, i) => attendance[i]).sort((a, b) => a - b).slice(0, 3);

    return 10000 * rank.indexOf(possible[0]) + 100 * rank.indexOf(possible[1]) + rank.indexOf(possible[2]);
}