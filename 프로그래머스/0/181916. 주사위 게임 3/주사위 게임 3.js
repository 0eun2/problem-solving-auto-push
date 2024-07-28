function solution(a, b, c, d) {
    const nums = [a, b, c, d];
    let dice = {}
    
    for (let i of nums) {
        dice[i] = (dice[i] || 0) + 1; 
    }
    
    const entries = Object.entries(dice).sort((a, b) => b[1] - a[1]);
    
    switch(entries.length){
        case 1:
            return 1111 * a;
        case 2:
            const p = Number(entries[0][0]);
            const q = Number(entries[1][0]);
            if(entries[0][1] === 3) return (10 * p + q) ** 2;
            else return (p + q) * Math.abs(p - q);
        case 3:
            return Number(entries[1][0]) * Number(entries[2][0]);
        case 4:
            return Math.min(...nums);
    }
}