
//풀이
//구현

function solution(places) {
    const move = [{x: -1, y: 0}, {x: 0, y: 1}, {x: 1, y: 0}];

    const find = ({ startX, startY, n, m, hall }) => {
        return move.map((cor, index) => {
            const nowX = n + move[index].x;
            const nowY = m + move[index].y;

            if (nowX < 0 || nowX >= 5 || nowY < 0 || nowY >= 5) return "NONE";

            if (nowX === startX && nowY === startY) return "STARTPOINT";
            else if (hall[nowX][nowY] === 'P') return "PEOPLE";
            else if (hall[nowX][nowY] === 'O') return "TABLE";
            else if (hall[nowX][nowY] === 'X') return "PARTITION";
        });
    }

    const checkManhattanDistance = ({ n, m, hall }) => {
        const OFFENSE = true;
        const OBEY = false;

        const searchArea = find({ startX: n, startY: m, n, m, hall });
        let flag = false;
        searchArea.forEach((now, index) => {
            if (now === "PEOPLE") flag = true;
            else if (now === "TABLE") {
                const area = find({
                    startX: n, 
                    startY: m, 
                    n: n + move[index].x, 
                    m: m + move[index].y, 
                    hall 
                });

                area.forEach(result => {
                    if (result === "PEOPLE") flag = true;
                });
            }
        });

        if(flag) return OFFENSE;
        else return OBEY;
    }

    const checkHall = (hall) => {
        for (let i = 0; i < 5; i++) {
            for (let j = 0; j < 5; j++) {
                if (hall[i][j] === 'P') {
                    let result = false;

                    result = checkManhattanDistance({ n: i, m: j, hall });

                    if (result) return 0;
                }
            }
        }
        return 1;
    }

    return places.map(hall => checkHall(hall));
}
