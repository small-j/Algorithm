#include<iostream>
#include<string>
#include<vector>
using namespace std;
int alpha[26] = { 3, 2, 1, 2, 3, 3, 3, 3, 1, 1, 3, 1, 3, 3, 1, 2, 2, 2, 1, 2, 1, 1, 2, 2, 2, 1 };
vector<int> v1, v2;
bool cal()
{
	if (v1.size() == 1) {
		if (v1[0] % 2 == 0) cout << "You're the winner?";
		else cout << "I'm a winner!";
		return true;
	}
	for (int i = 0; i < v1.size(); i += 2) {
		if (i + 1 == v1.size()) {
			v2.push_back(v1[i] % 10);
			break;
		}
		v2.push_back((v1[i] + v1[i + 1]) % 10);
	}

	v1.clear();
	for (int i = 0; i < v2.size(); i++)
		v1.push_back(v2[i]);
	v2.clear();
	return false;
}
int main()
{
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i += 2) {
		if (i + 1 == str.length()) {
			v1.push_back(alpha[(int)str[i] - 65] % 10);
			break;
		}
		int num = (alpha[(int)str[i] - 65]) + (alpha[(int)str[i + 1] - 65]);
		v1.push_back(num % 10);
	}
	while (true) {
		if (cal()) break;
	}
}
