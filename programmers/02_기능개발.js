
//풀이
//구현

function solution(progresses, speeds) {
    var answer = [];
    let Max = 0, cnt = 1;
    for(let i = 0; i<progresses.length; i++) {
        let timeItTakes = Math.floor((100 - progresses[i]) / speeds[i]);
        if((100 - progresses[i]) % speeds[i] !== 0) timeItTakes += 1;
        if(Max >= timeItTakes) cnt++;
        else {
            Max = timeItTakes;
            if(i !== 0) {
                answer.push(cnt);
                cnt = 1;
            }
        }
    }
    answer.push(cnt);
    return answer;
}
