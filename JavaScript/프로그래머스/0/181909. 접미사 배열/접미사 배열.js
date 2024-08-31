function solution(my_string) {
    return Array.from(my_string)
        .map((_, i) => my_string.substring(i))
        .sort();
}