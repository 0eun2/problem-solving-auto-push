function solution(arr) {
    let answer = 0;
    
    while(true){
        for (let i = 0; i < arr.length; i++) {
            if ((arr[i] >= 50 && !(arr[i] % 2)) || (arr[i] < 50 && arr[i] % 2)) break;
            if (i === arr.length - 1) return answer;
        }
        
        answer++;
        
        arr = arr.map((v) => {
            if (v >= 50 && !(v % 2)) return v / 2;
            else if (v < 50 && v % 2) return v * 2 + 1;
        });
    }    
}