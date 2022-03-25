
//풀이
//재귀, 구현

function solution(orders, course) {
    var answer = [];
    let findedSubStr = {};
    let maxCheck = {};
    let Max = 0;
    
    let ordersArray = orders.map(order => order.split("").sort().join(""));
    
    const checkStrLenMax = (a, b) => Max = Math.max(a, b);
    
    const strExist = (str) => findedSubStr.hasOwnProperty(str);
    
    const makeSubStr = ({str, resultStr, now, depth}) => {
        if (depth === 0) {
            strExist(resultStr) ? ++findedSubStr[resultStr] : findedSubStr[resultStr] = 1;
            
            checkStrLenMax(Max, findedSubStr[resultStr]);
            
            return;
        }
        
        for (let i = now + 1; i < str.length; i++)
            makeSubStr({str, resultStr: resultStr + str[i], now: i, depth: depth - 1});
    }
    
    ordersArray.forEach(order => {
        course.forEach(num => {
            if (num <= order.length) makeSubStr({str: order, resultStr: "", now: -1, depth: num});
            
            maxCheck[num] = Math.max(maxCheck[num] || 0, Max);
            Max = 0;
        });
    });
    
    Object.keys(findedSubStr).forEach(key => {
        findedSubStr[key] > 1
        && findedSubStr[key] === maxCheck[key.length] 
        && answer.push(key);
    });
    
    return answer.sort();
}
