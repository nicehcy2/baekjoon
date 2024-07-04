const readline = require('readline');

let data = [];

function Parse() {
    let board = data.slice(0, 5);
    let order = data.slice(5);

    return {board, order};
}

function checkBingo(visited) {

    let count = 0;

    for(let i=0; i<5; i++){
        let cnt = 0;
        for(let j=0; j<5; j++){
            if (visited[i][j] === true) {
                cnt++;
            }
        }
        if (cnt == 5){
            count++;
        }
    }

    for(let i=0; i<5; i++){
        let cnt = 0;
        for(let j=0; j<5; j++){
            if (visited[j][i] === true) {
                cnt++;
            }
        }
        if (cnt == 5){
            count++;
        }
    }

    let cnt =0;
    for(let i=0; i<5; i++){
        if (visited[i][i] === true){
            cnt++;
        }
    }
    if (cnt === 5) count++;

    cnt =0;
    for(let i=0; i<5; i++){
        if (visited[i][4- i] === true){
            cnt++;
        }
    }
    if (cnt === 5) count++;

    return count;
}

function findNum(board, num) {

    for(let i=0; i<5; i++){
        for(let j=0; j<5; j++){
            if (board[i][j] === num) {
                return {i, j};
            }
        }
    }
}

function Solution() {

    let answer = 0;

    const parseData = Parse();
    let order = parseData.order;
    let board = parseData.board;

    let visited = Array.from({length:5}, () => Array.from({length: 5}, () => false));

    for (let i=0; i<5; i++) {
        for(let j=0; j<5; j++) {
            
            let pos = findNum(board, order[i][j]);
            visited[pos.i][pos.j] = true;
            answer++;

            if (checkBingo(visited) >= 3) {
                console.log(answer);
                return;
            }
        }
    }
}

(async () => {
    let rl = readline.createInterface({ input: process.stdin });

    for await (const line of rl) {
        if (!line) {
            rl.close();
        } else {
            let row = line.split(' ').map(Number);
            data.push(row);
        }
    }

    Solution();

    process.exit();
})();
