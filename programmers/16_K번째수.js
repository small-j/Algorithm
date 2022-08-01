
//풀이
//완전탐색

function solution(array, commands) {
    var answer = [];
    
    const cutArr = (start, end, values) => {
        const arr = [];
        for (let i = start - 1; i < end; i++) {
            arr.push(values[i]);
        }
        
        return arr;
    }
    
    const findKthNumber = ([start, end, index]) => {
        const arr = cutArr(start, end, array).sort((a, b) => a - b);
        return arr[index - 1];
    } 

    answer = commands.map(findKthNumber);
    
    return answer;
}
