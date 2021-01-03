
//풀이
//분할정복 거듭제곱, 수학

#include<iostream>
using namespace std;
typedef long long ll;
ll pow(ll num)
{
	return num * num;
}
ll spare(ll num)
{
	if (num == 1) return 2;
	if (num == 0) return 1;
	ll n = (pow(spare(num / 2))) % 1000000007;
	if (num % 2 != 0) n = n * 2 % 1000000007;
	return n;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		ll N;
		scanf("%lld", &N);
		if (N == 1) printf("%d\n", 1);
		else if (N == 2) printf("%d\n", 1);
		else printf("%lld\n", spare(N - 2));
	}
}
