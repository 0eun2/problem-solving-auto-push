function solution(intStrs, k, s, l) {
    return intStrs.map((x) => Number(x.substr(s, l))).filter((x) => x > k);
}