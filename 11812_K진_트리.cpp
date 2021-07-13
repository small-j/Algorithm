
//풀이
//수학, 트리

#include<iostream>
#include<stack>
#include<math.h>
using namespace std;
typedef long long ll;
int main()
{
	ll N, K, Q;
	scanf("%lld%lld%lld", &N, &K, &Q);
	while (Q--) {
		ll x, y, cnt = 0;
		stack<ll> xx;
		stack<ll> yy;
		scanf("%lld%lld", &x, &y);
		if (K == 1) {
			printf("%lld\n", abs(x - y));
			continue;
		}
		while (x != 1) {
			xx.push(x);
			x = (x + (K - 2)) / K;
		}
		while (y != 1) {
			yy.push(y);
			y = (y + (K - 2)) / K;
		}
		xx.push(1);
		yy.push(1);
		x = xx.top();
		y = yy.top();
		while (x == y) {
			xx.pop();
			yy.pop();
			if (xx.empty() || yy.empty()) break;
			x = xx.top();
			y = yy.top();
		}
		printf("%lld\n", (ll)xx.size() + (ll)yy.size());
	}
}
