#include<iostream>
using namespace std;
int main()
{
	int N, half = 0, quarter = 0, three = 0, sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		if (a == '1' && c == '2') half++;
		else if (a == '1' && c == '4') quarter++;
		else three++;
	}

	sum += (half / 2);
	half %= 2;
	if (quarter <= three) {
		sum += three;
		if (half > 0) sum++;
	}
	else {
		sum += three;
		quarter -= three;
		if (half > 0 && quarter >= 2) {
			sum++;
			quarter -= 2;
			half = 0;
		}
		if (half > 0) sum++;
		else {
			sum += quarter / 4;
			if (quarter % 4 != 0) sum++;
		}
	}
	cout << sum << "\n";
}
