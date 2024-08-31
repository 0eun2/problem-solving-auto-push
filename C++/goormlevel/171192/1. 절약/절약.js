const readline = require('readline');

(async () => {
	let rl = readline.createInterface({ input: process.stdin });
	let input = [];
	for await (const line of rl) {
		input.push(line.split(' '));
		if(!line) rl.close();
	}	
	const trade = input.slice(1);
	console.log(solution(trade));
	
	process.exit();
})();

function solution(trade){
	let money = 0;
	for(const [c, v] of trade){
		if(c === "in") money += Number(v);
		else money -= Number(v);
		
		if(money < 0) return "fail";
	}
	return "success";
}
