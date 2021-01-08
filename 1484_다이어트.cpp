
//풀이
//수학, 두포인터

#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
typedef long long ll;
int main()
{
	ll G;
	vector<ll> v;
	scanf("%lld", &G);
	ll start = (ll)sqrt(G);
	while(1)
	{
		ll current = start * start, weight;
		if (current < G) {
			start++;
			continue;
		}
		for (ll j = 1; j < start; j++)
		{
			weight = current - j * j;
			if (weight == G) {
				v.push_back(start);
				continue;
			}
		}
		if (weight > G) break;
		start++;
	}
	if (v.size() == 0) printf("-1\n");
	else for (int i = 0; i < v.size(); i++) printf("%lld\n", v[i]);
}
