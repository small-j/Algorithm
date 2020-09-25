#include<iostream>
#include<stack>
#include<string>
using namespace std;
stack<int> passport[105];
int main()
{
	int N, k, n[105];
	string str = "YES";
	cin >> N >> k;

	for (int i = 0; i < N; i++) {
		cin >> n[i];
		if (i == 0) {
			passport[0].push(n[i]);
			continue;
		}
		bool flag = true;
		for (int j = 0; j < k; j++) {
			if (passport[j].empty() || passport[j].top() < n[i]) {
				passport[j].push(n[i]);
				flag = false;
				break;
			}
		}
		if (flag) {
			str = "NO";
			break;
		}
	}
	cout << str << "\n";
}
