
//풀이
//완전탐색

function solution(answers) {
    var answer = [];
    let chooseNumberList = [
        { numbers: [1, 2, 3, 4, 5], index: 0, score: 0 },
        { numbers: [2, 1, 2, 3, 2, 4, 2, 5], index: 0, score: 0 },
        { numbers: [3, 3, 1, 1, 2, 2, 4, 4, 5, 5], index: 0, score: 0 }
    ];
    
    const calcIndex = (index, arr) => {
        return arr.length === index + 1 ? 0 : index + 1;
    }
    
    const marking = (answer, chooseNumber) => {
        const {numbers, index, score} = chooseNumber;
        if (answer === numbers[index]) chooseNumber.score++;
        chooseNumber.index = calcIndex(index, numbers);
    }
    
    const compareAnswer = (answer) => {
        chooseNumberList.forEach((value) => marking(answer, value));
    }
    
    const findMaxScore = () => {
        let max = 0;
        const scoreArr = chooseNumberList.map((value) => value.score);
        max = Math.max(...scoreArr, max);
        
        return max;
    }
    
    const addMaxScore = (maxValue) => {
         chooseNumberList
             .map((value) => value.score)
             .forEach((score, index) => {
                if (score === maxValue) answer.push(index + 1);
            });
    }
    
    answers.forEach(compareAnswer);
    addMaxScore(findMaxScore());
    
    return answer;
}
