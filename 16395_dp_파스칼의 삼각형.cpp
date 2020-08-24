#include<iostream>
using namespace std;
int dist[35][35];
int main()
{
	int n, k;
	cin >> n >> k;
	dist[1][1] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1 || j == i) dist[i][j] = 1;
			else dist[i][j] = dist[i - 1][j - 1] + dist[i - 1][j];
		}
	}
	cout << dist[n][k] << endl;
}
