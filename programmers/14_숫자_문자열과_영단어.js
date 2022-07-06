
//풀이
//구현

function solution(s) {
    var answer = 0;
    const numberEn = {
        zero: "0",
        one: "1",
        two: "2", 
        three: "3", 
        four: "4", 
        five: "5", 
        six: "6", 
        seven: "7", 
        eight: "8", 
        nine: "9"
    };
        
    const findNumberWord = (i) => {
        let cnt = i;
        let findNum = "";
        
        while (!numberEn[findNum]) {
            findNum += s[cnt];
            cnt++;
        }
        
        return {cnt: cnt - 1, result: numberEn[findNum]};
    }
    
    const regex = /[a-z]/;
    let fixedValue = "";
    
    for (let i = 0; i < s.length; i++) {
        if (regex.test(s[i])) {
            const {cnt, result} = findNumberWord(i);
            i = cnt;
            fixedValue += result;
        }
        else fixedValue += s[i];
    }
    
    answer = Number(fixedValue);
    return answer;
}
