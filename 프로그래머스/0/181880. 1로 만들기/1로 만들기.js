function solution(num_list) {
    var answer = 0;
    
    while (!num_list.every(v => v === 1)) {
        
        num_list = num_list.map(v => {
            if (v === 1) return v;
            
            answer++;
            
            if (v % 2) return (v - 1) / 2;
            return v / 2;
        });
    }
    
    return answer;
}