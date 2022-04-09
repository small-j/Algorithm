
//풀이
//구현, 정렬, 정규식

function solution(str1, str2) {
    var answer = 0;
    
    const checkStrRegex = (str) => {
        const regex = /^[A-Za-z]{2}$/;
        return regex.test(str);
    }
    
    const makeSubStr = (str) => {
        const arr = [];
        
        for (let i = 0; i < str.length - 1; i++) {
            const sub = str[i] + str[i + 1];
            checkStrRegex(sub) && arr.push(sub.toLowerCase());
        }
        
        return arr;
    }
    
    const findSameStr = (startIndex, findStr, arr) => {
        let sameStrCnt = 0;
        
        for (let i = startIndex; i < arr.length; i++) {
            if (arr[i] === findStr) sameStrCnt++;
            else break;
        }
        
        return sameStrCnt;
    }
    
    const compareSubStr = (arr1, arr2) => {
        let intersection = 0;
        let union = 0;
        let arr1StartIndex = 0;
        let arr2Len = arr2.length;
        
        arr1.sort();
        arr2.sort();
        
        while(arr1StartIndex < arr1.length) {
            const arr2StartIndex = arr2.indexOf(arr1[arr1StartIndex]);
            
            if (arr2StartIndex === -1) {
                arr1StartIndex++;
                union++;
                continue;
            }
            
            const arr1StrCnt = findSameStr(arr1StartIndex, arr1[arr1StartIndex], arr1);
            const arr2StrCnt = findSameStr(arr2StartIndex, arr1[arr1StartIndex], arr2);
            arr1StartIndex += arr1StrCnt;
            arr2Len -= arr2StrCnt;
            
            union += Math.max(arr1StrCnt, arr2StrCnt);
            intersection += Math.min(arr1StrCnt, arr2StrCnt);
        }
        
        union += arr2Len;
        
        return {intersection, union};
    }
    
    const {intersection, union} = compareSubStr(makeSubStr(str1), makeSubStr(str2));
    
    if (intersection === 0 && union === 0) answer = 65536;
    else answer = Math.floor((intersection / union) * 65536);
    
    return answer;
}
