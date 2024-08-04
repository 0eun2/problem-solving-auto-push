function solution(myString) {
    return myString.split('').map(v => v.charCodeAt() < 'l'.charCodeAt() ? 'l' : v).join('');
}