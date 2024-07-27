function solution(my_string, queries) {
    let arr = my_string.split('');
    
    queries.forEach(([s, e]) => {
        let reverseArr = arr.slice(s, e + 1).reverse();
        arr.splice(s, e - s + 1, ...reverseArr);
    })
    
    return arr.join('');
}