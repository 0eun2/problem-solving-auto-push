function solution(my_string, index_list) {
    return index_list.map((num) => my_string[num]).join('');
}