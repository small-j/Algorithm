
//풀이
//다이나믹 프로그래밍(LCS), 문자열

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int dp[1050][1050];
string a, b;
void findStr(int x, int y)
{
	if (dp[x - 1][y] == dp[x][y])findStr(x - 1, y);
	else if (dp[x][y - 1] == dp[x][y]) findStr(x, y - 1);
	else {
		if(dp[x][y] != 1) findStr(x - 1, y - 1);
		cout << a[x-1];
	}
	return;
}
int main()
{
	cin >> a >> b;

	for (int i = 1; i <= a.length(); i++) {
		for (int j = 1; j <= b.length(); j++) {
			if (a[i - 1] == b[j - 1])dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	cout << dp[a.length()][b.length()] << "\n";
	if (dp[a.length()][b.length()] != 0) findStr(a.length(), b.length());
}
