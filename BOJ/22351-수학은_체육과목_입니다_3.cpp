
//풀이
//문자열, 브루트포스

#include<iostream>
#include<string>
using namespace std;
int main()
{
	string S;
	cin >> S;
	int startLen, endLen = 0, prevNum;
	for (int i = 1; i <= 3; i++) {
		prevNum = stoi(S.substr(0, i));
		int nowIndex = i, prevLen = i;
		bool flag = true;
		startLen = i;
		while (nowIndex < S.length()) {
			flag = true;
			for (int j = prevLen; j <= 3; j++) {
				int nowNum = stoi(S.substr(nowIndex, j));
				if (prevNum + 1 == nowNum) {
					prevNum = nowNum;
					prevLen = to_string(prevNum).length();
					nowIndex += prevLen;
					endLen = prevLen;
					flag = false;
					break;
				}
			}
			if (flag) break;
		}
		if (!flag && endLen != 0) break;
	}

	if (endLen == 0) cout << S << " " << S;
	else cout << S.substr(0, startLen) << " " << prevNum;
	
}
