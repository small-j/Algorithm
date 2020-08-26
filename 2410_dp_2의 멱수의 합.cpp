#include<iostream>
using namespace std;
int dist[1000005];
int main()
{
	int N;
	cin >> N;
	
	for (int i = 0; i <= N; i++)
		dist[i] = 1;
	for (int i = 2; i <= N; i *= 2) {
		for (int j = 0; j <= N; j++) {
			if (j < i) dist[j] = dist[j];
			else
				dist[j] = (dist[j - i] + dist[j]) % 1000000000;
		}
	}
	cout << dist[N] << endl;
}
