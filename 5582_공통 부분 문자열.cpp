
//풀이
//다이나믹 프로그래밍

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int dp[4010][4010];
string a, b;
int main()
{
	int Max = 0;
	cin >> a >> b;

	for (int i = 1; i <= a.length(); i++) {
		for (int j = 1; j <= b.length(); j++) {
			if (a[i - 1] == b[j - 1])dp[i][j] = dp[i - 1][j - 1] + 1;
			Max = max(dp[i][j], Max);
		}
	}

	cout << Max << "\n";
}
