
//풀이
//에라토스테네스의 체, 완전탐색

function solution(nums) {
    var answer = 0;
    const checkArr = nums.map(num => false);
    const sieve = new Array(3000);

    //에라토스테네스의 체로 한번 수를 거르고 
    //나올 수 있는 가장 큰 수(998 + 999 + 1000) = 2997 즉 3천까지만 소수인 수들 구해놓고
    //배열에 check해서 해당 수가 소수인지 판별한다
    const sieveOfEratosthenes = () => {
        sieve[0] = true;
        sieve[1] = true;

        for (let i = 2; i < 3000; i++) {
            if (sieve[i]) continue;

            let now = i, num = 2;

            while(now * num < 3000) {
                sieve[now * num] = true;
                num++;
            }
        }
    }


    const recur = (now, cnt, sum) => {
        if (cnt === 3) {
            if (!sieve[sum]) answer++;
            return;
        }

        for (let i = now; i < nums.length; i++) {
            if (!checkArr[i]) {
                checkArr[i] = true;
                recur(i + 1, cnt + 1, sum + nums[i]);
                checkArr[i] = false;
            }
        }
    }

    sieveOfEratosthenes();
    recur(0, 0, 0);

    return answer;
}
