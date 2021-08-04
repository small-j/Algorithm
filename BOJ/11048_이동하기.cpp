
//풀이
//dynamic programming

#include<iostream>
using namespace std;
int dist[1005][1005];
int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> dist[i][j];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (dist[i - 1][j] < dist[i][j - 1]) dist[i][j] += dist[i][j - 1];
			else dist[i][j] += dist[i - 1][j];
		}
	}
	cout << dist[N][M] << endl;
}
