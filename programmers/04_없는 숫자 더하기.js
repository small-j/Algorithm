
//풀이
//구현

function compareFunc(a, b) {
    return a - b;
}

function solution(numbers) {
    let answer = 0;
    let findNumber = 0;

    numbers.sort(compareFunc);

    numbers.forEach(num => {
        while(num !== findNumber) {
            answer += findNumber;
            findNumber++;
        }
        findNumber++;
    })

    const lastNumber = numbers[numbers.length - 1] + 1;
    for (let i = lastNumber; i <= 9; i++) answer += i;
    return answer;
}


//직관적인 코드를 위한 리팩터링

function compareFunc(a, b) {
    return a - b;
}

function plusNonexistentNumber(arr) {
    let result = 0;
    let findNumber = 0;
    
    arr.forEach(num => {
        while (num !== findNumber) {
            result += findNumber;
            findNumber++;
        }
        findNumber++;
    });
    
    return result;
}

function plusRemainNumber(lastNumber) {
    let result = 0;
    for (let i = lastNumber; i <= 9; i++) result += i;
    return result;
}

function solution(numbers) {
    let answer = 0;
    
    numbers.sort(compareFunc);
    answer = plusNonexistentNumber(numbers);
    
    const lastNumber = numbers[numbers.length - 1] + 1;
    answer += plusRemainNumber(lastNumber);
    
    return answer;
}
