
//풀이
//수학

#include<iostream>
using namespace std;
typedef long long ll;
ll N, M, sum = 0;
ll prime[11];
void overlapNumRemove(ll nowIndex, ll now, ll deep, ll primeSum) {

	if (now == deep) {
		if (M >= primeSum) {
			if(deep % 2 == 1) sum += M / primeSum;
			else sum -= M / primeSum;
		}
		return;
	}

	for (ll i = nowIndex; i < N; i++) {
		primeSum *= prime[i];
		overlapNumRemove(i + 1, now + 1, deep, primeSum);
		primeSum /= prime[i];
	}
	return;
}
int main()
{
	cin >> N >> M;
	for (ll i = 0; i < N; i++) {
		cin >> prime[i];
		sum += M / prime[i];
	}

	for (ll i = 2; i <= N; i++) {
		overlapNumRemove(0, 0, i, 1);
	}

	cout << sum;
}
