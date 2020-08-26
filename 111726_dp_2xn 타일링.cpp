#include<iostream>
using namespace std;
int dist[1005];
int main()
{
	int n;
	cin >> n;
	dist[1] = 1;
	dist[2] = 2;
	for (int i = 3; i <= n; i++) {
		dist[i] = (dist[i - 2] + dist[i - 1]) % 10007;
	}
	cout << dist[n] << endl;
}
