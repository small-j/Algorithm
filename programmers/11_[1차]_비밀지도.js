
//풀이
//문자열, 구현

function solution(n, arr1, arr2) {
    var answer = [];
    
    const twoZegob = [1];
    let count = 1;
    for (let i = 1; i < n; i++) twoZegob.push(count *= 2);
    
    const makeBinary = (num) => {
        const binaryArr = [];
        let binaryNum = num;
        
        for (let i = n - 1; i >= 0; i--) {
            if (twoZegob[i] <= binaryNum) {
                binaryArr.push(1);
                binaryNum -= twoZegob[i];
            }
            else binaryArr.push(0);
        }
        
        return binaryArr;
    }
    
    const makeMap = (arr) => {
        return arr.map(num => makeBinary(num));
    }
    
    const compareMap = (column1, column2) => {
        return column1.map((nowField, index) => {
            return nowField === 1 || column2[index] === 1 ? "#" : " ";
        });
    }
    
    const map1 = makeMap(arr1);
    const map2 = makeMap(arr2);
    
    for (let i = 0; i < n; i++) answer.push(compareMap(map1[i], map2[i]).join(""));
    
    return answer;
}
