
//풀이
//수학, 백트래킹

#include<iostream>
#include<string>
#include<stack>
using namespace std;
stack<int> p;
bool check[55] = { false };
string str;
int len, cnt = 0;
bool recur(int index)
{
	if (index <= 0) {
		if (index == 0) {
			if (check[str[index] - 48]) return false;
			else p.push(str[index] - 48);
		}
		while (!p.empty()) {
			cout << p.top() << " ";
			p.pop();
		}
		return true;
	}
	int num = (int)(str[index - 1] - 48) * 10 + (int)(str[index] - 48);
	if (num > cnt || check[num] || str[index - 1] == '0') {
		if (check[str[index] - 48]) return false;
		p.push(str[index] - 48);
		check[(int)str[index] - 48] = true;
		index--;
		if(recur(index)) return true;
		index++;
		check[(int)str[index] - 48] = false;
		p.pop();
	}
	else {
		if (check[num]) return false;
		p.push(num);
		check[num] = true;
		index-=2;
		if (recur(index)) return true;
		index+=2;
		check[num] = false;
		p.pop();
		if (check[str[index] - 48]) return false;
		p.push(str[index] - 48);
		check[(int)str[index] - 48] = true;
		index--;
		if (recur(index)) return true;
		index++;
		check[(int)str[index] - 48] = false;
		p.pop();
	}
	return false;
}
int main()
{
	cin >> str;
	len = str.length();
	int index = len - 1;
	if (len > 9) cnt = 9 + (len - 9) / 2;
	else cnt = len;
	recur(index);
	return 0;
}
