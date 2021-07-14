
//풀이
//브루트포스

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> n;
vector<char> o;
int N, num[30], Max = -2147483647;
char O[30];
int calculation(int a, int b, char Operator) {
	if (Operator == '+') return a + b;
	else if (Operator == '*') return a * b;
	else if (Operator == '-') return a - b;
}
void recur(int deep, bool flag)
{
	if (deep > N / 2) {
		int sum = n[0], s = o.size();
		for (int i = 0; i < s; i++)
			sum = calculation(sum, n[i + 1], o[i]);
		Max = max(sum, Max);
		return;
	}
	if (flag) {
		int f = n[n.size() - 1];
		n.pop_back();
		n.push_back(calculation(f, num[deep], O[deep]));
		recur(deep + 1, !flag);
		n.pop_back();
		n.push_back(f);
	}
	n.push_back(num[deep]);
	o.push_back(O[deep]);
	recur(deep + 1, true);
	n.pop_back();
	o.pop_back();
	return;
}
int main()
{
	cin >> N;
	cin >> num[0];
	for (int i = 1; i <= N / 2; i++) {
		cin >> O[i] >> num[i];
	}
	n.push_back(num[0]);
	recur(1, true);
	cout << Max << endl;
}
