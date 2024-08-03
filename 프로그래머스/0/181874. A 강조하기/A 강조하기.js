function solution(myString) {
    return myString.split('').map(v => {
        if (v === 'a') return 'A';
        if (v !== 'A' && v == v.toUpperCase()) return v.toLowerCase();
        return v;
    }).join('');
    
}