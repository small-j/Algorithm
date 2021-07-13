
//풀이
//dp

#include<iostream>
using namespace std;
typedef long long ll;
ll dist[1001];
ll recur(ll num) 
{
	if (dist[num]) return dist[num];
	ll result = 0;
	for (int i = 1; i <= (num / 2); i++)
		result += recur(i);
	dist[num] = result + 1;
	return result + 1;
}
int main()
{
	int T;
	scanf("%d", &T);
	dist[1] = 1;
	while (T--) {
		ll num;
		scanf("%lld", &num);
		printf("%lld\n", recur(num));
	}
}
