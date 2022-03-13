
//풀이
//투포인터, 구현

function solution(lottos, win_nums) {
    let answer = [];    

    const compare = (a, b) => {
        return a - b;
    }

    const sortArray = (arr) => {
        arr.sort(compare);
    }

    const matchTest = (arr1, arr2) => {
        let pointer1 = 0, pointer2 = 0;
        let invisibleNumCnt = 0, matchNumCnt = 0;

        while (pointer1 < 6 && pointer2 < 6) {
            if (arr1[pointer1] === arr2[pointer2]) {
                matchNumCnt++;
                pointer1++;
                pointer2++;
            } else if (arr1[pointer1] < arr2[pointer2]) {
                if (arr1[pointer1] === 0) invisibleNumCnt++;
                pointer1++;
            } else {
                pointer2++;
            }
        }

        return { invisible: invisibleNumCnt, match: matchNumCnt};
    }

    const rank = (num) => {
        switch (num) {
            case 6:
                return 1;
            case 5:
                return 2;
            case 4:
                return 3;
            case 3:
                return 4;
            case 2:
                return 5;
            default:
                return 6;
        }
    }

    sortArray(lottos);
    sortArray(win_nums);

    const result = matchTest(lottos, win_nums);

    answer = [rank(result.invisible + result.match), rank(result.match)];
    return answer;
}
