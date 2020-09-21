#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
vector<pair<ll, ll>> v;
int main()
{
	ll N, x;
	scanf("%lld%lld", &N, &x);
	for (ll i = 0; i <= N; i++) {
		ll Ai, j;
		scanf("%lld%lld", &Ai, &j);
		v.push_back({ j, Ai });
	}

	ll sum = x * v[0].second % 1000000007;
	for (int i = 1; i <= N; i++) {
		sum += v[i].second;
		if(i != N) sum = sum * x % 1000000007;
	}
	printf("%lld\n", sum);
}
