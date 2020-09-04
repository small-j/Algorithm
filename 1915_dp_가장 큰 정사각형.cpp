#include<iostream>
#include<algorithm>
using namespace std;
int dp[1005][1005];
int main()
{
	int n, m, Max = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &dp[i][j]);
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (dp[i][j] == 0) continue;
			if (dp[i - 1][j - 1] == 0 || dp[i - 1][j] == 0 || dp[i][j - 1] == 0) dp[i][j] = 1;
			else {
				int Min;
				Min = min(dp[i - 1][j - 1], dp[i - 1][j]);
				Min = min(Min, dp[i][j - 1]);
				dp[i][j] = Min + 1;
			}
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			Max = max(Max, dp[i][j]);

	cout << Max * Max;
}
