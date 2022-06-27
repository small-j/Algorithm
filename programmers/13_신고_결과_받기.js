
//구현, Set

function solution(id_list, report, k) {
    var answer = [];
    const reportedRecord = {};
    const resultMail = {};
    
    const writeReport = (record) => {
        const [user, reportUser] = record.split(" ");
        if (!reportedRecord[reportUser]) 
            reportedRecord[reportUser] = new Set();
        reportedRecord[reportUser].add(user);
    }
    
    const initResultMail = () => {
        id_list.forEach(id => resultMail[id] = 0);
    }
    
    const isExistedUser = (obj, id) => {
        return obj[id] ? true : false;
    }
    
    const transSetToArray = (set) => {
        return Array.from(set)
    }
    
    const postResultMail = (id) => resultMail[id]++;
    
    const countReportedUser = (id) => {
        if (isExistedUser(reportedRecord, id)) {
            const users = transSetToArray(reportedRecord[id]);
            
            users.length >= k && users.forEach(postResultMail);
        }
    }
        
    const countResultMail = (id) => resultMail[id];
    
    initResultMail();
    report.forEach(writeReport);
    Object.keys(reportedRecord).forEach(countReportedUser);
    answer = id_list.map(countResultMail);
    
    return answer;
}
