
//풀이
// greedy, 정렬

function solution(nums) {
    var answer = 0;
    nums.sort((a, b) => {
       return a - b; 
    });
    for(let i = 0; i < nums.length; i++) {
        if(nums[i] != nums[i-1]) { answer++; }
        if(answer>= nums.length / 2) { break; }
    }
    return answer;
}
