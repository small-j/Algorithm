#include<iostream>
using namespace std;
int book[300005];
int main()
{
	int N, cnt = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> book[i];
	int find = N;
	for (int i = N - 1; i >= 0; i--) {
		if (book[i] == find) find--;
		else cnt++;
	}
	cout << cnt << "\n";
}
