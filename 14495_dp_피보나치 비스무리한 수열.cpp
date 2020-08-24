#include<iostream>
using namespace std;
long long dist[117];
long long f(long long num)
{
	if (dist[num] != 0) return dist[num];
	return dist[num] = f(num - 1) + f(num - 3);
}
int main()
{
	long long n;
	cin >> n;
	dist[1] = 1;
	dist[2] = 1;
	dist[3] = 1;
	cout << f(n) << endl;
}
