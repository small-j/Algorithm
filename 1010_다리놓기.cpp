
//풀이
//dynamic programming

#include<iostream>
using namespace std;
int dist[35][35];
int main()
{
	for (int i = 1; i < 31; i++)
		dist[1][i] = i;

	for (int i = 2; i < 31; i++) {
		for (int j = i; j < 31; j++) {
			for (int k = 1; k < j; k++) {
				dist[i][j] += dist[i - 1][k];
			}
		}
	}
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		cout << dist[N][M] << endl;
	}
}
