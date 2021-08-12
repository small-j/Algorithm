#include<iostream>
using namespace std;
typedef long long ll;
int main()
{
	ll t, k, N, dp[21][210], cnt = 1;
	cin >> t;
	while (t--) {
		cin >> k >> N;
		dp[1][0] = 1;
		dp[1][1] = 1;
		while (cnt < k) {
			cnt++;
			dp[cnt][0] = 1;
			ll start = 0, end = cnt * (cnt + 1) / 2;
			for (ll i = 1; i < cnt + 1; i++) {
				dp[cnt][i] = dp[cnt][i - 1] + dp[cnt-1][i];
			}
			for (ll i = cnt + 1; i <= end / 2; i++) {
				dp[cnt][i] = dp[cnt][i - 1] - dp[cnt-1][start] + dp[cnt-1][i];
				start++;
			}
			for (ll i = 0; i <= end / 2; i++)
				dp[cnt][end - i] = dp[cnt][i];
		}
		cout << dp[k][N] << "\n";
	}
}
