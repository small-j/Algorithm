#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
int dist[50005];
int dp(int n)
{
	if (dist[n] != 1e9) return dist[n];
	int num = sqrt(n);
	if (n - num * num == 0) return 1;

	for (int i = num - 1; i >= 1; i--) {
		dist[n] = min(dist[n], 1 + dp(n - i * i));
	}
	return dist[n];
}
int main()
{
	int n;
	cin >> n;
	fill(dist, dist + n + 1, 1e9);
	dist[1] = 1;
	dist[2] = 2;
	dist[3] = 3;
	cout << dp(n) << endl;
}
