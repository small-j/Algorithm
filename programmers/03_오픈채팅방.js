
//구현, Map

function solution(record) {
    var answer = [];
    let chatRoomMember = new Map();
    
    const splitMessage = (message) => {
        return message.split(" ");
    }
    
    const setMap = (map, key, value) => {
        map.set(key, value);
    }
    
    const userEnter = (message) => {
         setMap(chatRoomMember, message[1], message[2]);
    }
    
    const userChange = (message) => {
         setMap(chatRoomMember, message[1], message[2]);
    }
    
    record.forEach(message => {
        const tempMessage = splitMessage(message);
        const action = tempMessage[0];
        if (action === "Enter" ) userEnter(tempMessage);
        if (action === "Change" ) userChange(tempMessage);
    });
    
    record.forEach(message => {
        const tempMessage = splitMessage(message);
        const action = tempMessage[0];
        if (action === "Enter" ) answer.push(`${chatRoomMember.get(tempMessage[1])}님이 들어왔습니다.`);
        if (action === "Leave" ) answer.push(`${chatRoomMember.get(tempMessage[1])}님이 나갔습니다.`);
    });
    
    return answer;
}
