#include<iostream>
using namespace std;
typedef long long ll;
int main()
{
	ll n, W, s[16];
	cin >> n >> W;
	for (int i = 0; i < n; i++)
		cin >> s[i];

	bool flag = true;
	ll coin = 0;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] < s[i + 1] && coin == 0) {
			coin = W / s[i];
			W %= s[i];
		}
		if (s[i] > s[i + 1] && coin != 0) {
				W += coin * s[i];
				coin = 0;
		}
	}
	if (coin != 0) W += coin * s[n - 1];
	cout << W << "\n";
}
