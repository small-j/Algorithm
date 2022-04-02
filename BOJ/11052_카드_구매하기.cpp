
//풀이
//dp

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dp[10005][1005] = {0};
vector<int> p;

int main() {
	int N, num;

	cin >> N;

	while (true) {
		cin >> num;
		if (cin.eof()) break;
		p.push_back(num);
	}

	for (int i = 0; i < p.size(); i++) {
		if (i + 1 > N) break;

		for (int j = 1; j <= N; j++) {
			int nowP = i + 1;
			int remain = j - nowP;

			if (remain < 0) dp[nowP][j] = dp[nowP - 1][j];
			else dp[nowP][j] = max(dp[nowP][remain] + p[i], dp[nowP - 1][j]);

		}
	}
	
	cout << dp[p.size()][N];
} 
