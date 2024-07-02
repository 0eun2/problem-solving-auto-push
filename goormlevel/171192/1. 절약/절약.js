const readline = require('readline');

function solution(c, v){
	let money = 0;
	for(let i = 0; i < c.length; i++){
		if(c[i] === "in") money += v[i];
		else money -= v[i];
		
		if(money < 0) return "fail";
	}
	return "success";
}

(async () => {
	let rl = readline.createInterface({ input: process.stdin });
	
	let n = null;
	let c = [], v = [];
	
	for await (const line of rl) {
		if(!n) n = line;
		else{
			const input = line.split(' ');
			c.push(input[0]);
			v.push(parseInt(input[1]));
			if(--n === 0) rl.close();
		}
	}
	
	console.log(solution(c, v));
	process.exit();
})();
