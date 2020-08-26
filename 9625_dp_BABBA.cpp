#include<iostream>
#include<string>
using namespace std;
int main()
{
	int K, A = 1, B = 0;
	cin >> K;
	for (int i = 1; i <= K; i++) {
		int a = 0, b = 0;
		a += B;
		b += A + B;
		A = a;
		B = b;
	}
	cout << A << " " << B << endl;
}
