#include<iostream>
#include<string>
using namespace std;
int main()
{
	int eight = 0;
	string L, R;
	cin >> L >> R;
	if (L.length() != R.length()) {
		cout << 0;
		return 0;
	}
	else if (L == R) {
		for (int i = 0; i < L.length(); i++)
			if (L[i] == '8') eight++;
		cout << eight;
		return 0;
	}
	for (int i = 0; i < L.length() - 1; i++) {
		if (L[i] != R[i]) break;
		if (L[i] == '8') eight++;
	}
	cout << eight;
	return 0;
}