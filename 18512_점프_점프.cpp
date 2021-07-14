
//풀이
//수학, 브루트포스

#include<iostream>
using namespace std;
int main()
{
	int X, Y, P1, P2;
	cin >> X >> Y >> P1 >> P2;
	if (P1 < P2) {
		int num = P1;
		P1 = P2;
		P2 = num;
		num = X;
		X = Y;
		Y = num;
	}

	if (X == Y) {
		if ((P1 - P2) % X == 0) cout << P1 << "\n";
		else cout << -1 << "\n";
		return 0;
	}

	int cnt = 0;
	while (1) {
		if ((P1 - P2) % Y == 0) {
			cout << P1 << "\n";
			break;
		}
		P1 += X;
		cnt++;
		if (cnt > 100) {
			cout << -1 << "\n";
			break;
		}
	}
	return 0;
}
