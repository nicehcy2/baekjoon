// Run by Node.js
const readline = require('readline');

let data = new Array();

function solution() {
	const uniq = [...new Set(data[1])];
	
	uniq.sort((a,b) => {
		if (a>b) return 1;
		else return -1;
	});
	
	console.log(uniq.join(" ").concat("\n"));
}

(async () => {
	let rl = readline.createInterface({ input: process.stdin, output: process.stdout });
	
	for await (const line of rl) {
		if (!line) rl.close();
		else {
			let row = line.split(' ').map(Number);
			data.push(row);
		}
	}
	
	solution();
	
	process.exit();
})();
