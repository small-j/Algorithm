#include<iostream>
using namespace std;
int dist[1000005];
int dp(int num)
{
	if (dist[num] != 0) return dist[num];
	return dist[num] = (dp(num - 1) + dp(num - 2)) % 15746;
}
int main()
{
	int N;
	cin >> N;
	dist[1] = 1;
	dist[2] = 2;
	cout << dp(N) << endl;
}
