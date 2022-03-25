
//풀이
//구현

function solution(numbers, hand) {
    const KEYPAD_10 = 10;
    const KEYPAD_11 = 11;
    const distance = {
        2: [3, 1, 0, 1, 2, 1, 2, 3, 2, 3, 4, 4],
        5: [2, 2, 1, 2, 1, 0, 1, 2, 1, 2, 3, 3],
        8: [1, 3, 2, 3, 2, 1, 2, 1, 0, 1, 2, 2],
        0: [0, 4, 3, 4, 3, 2, 3, 2, 1, 2, 1, 1],
    };

    var answer = '';
    let leftThumb = KEYPAD_10;
    let rightThumb = KEYPAD_11;

    const findDistance = (nowKeypad, destinationKeypad) => {
        const result = distance[destinationKeypad];
        return result[nowKeypad];
    }

    const compareDistance = (keypad) => {
        const distanceFromLeft = findDistance(leftThumb, keypad);
        const distanceFromRight = findDistance(rightThumb, keypad);
        let chooseHand;

        if (distanceFromLeft === distanceFromRight) chooseHand = hand === "left" ? "L" : "R";
        else if (distanceFromLeft < distanceFromRight) chooseHand = "L";
        else chooseHand = "R";

        chooseHand === "L" ? leftThumb = keypad : rightThumb = keypad;
        return chooseHand;
    }

    const chooseThumb = (keypad) => {
        switch (keypad) {
            case 1:
            case 4:
            case 7:
                leftThumb = keypad;
                return "L";
            case 3:
            case 6:
            case 9:
                rightThumb = keypad;
                return "R";
            default:
                return compareDistance(keypad);
        }
    }

    answer = numbers.map(number => chooseThumb(number));

    return answer.join("");
}
