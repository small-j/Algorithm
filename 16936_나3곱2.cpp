
//풀이
//수학

#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
ll N, B[105];
bool flag;
vector<ll> v[101];
vector<ll> p;
int check(ll num)
{
	for (ll i = 1; i <= N; i++)
		if (B[i] == num) return i;
	return 0;
}
void recur(ll location, ll num)
{
	if (flag) return;
	if (location == N) {
		for (ll i = 0; i < p.size(); i++)
			printf("%lld ", p[i]);
		printf("\n");
		flag = true;
		return;
	}
	for (ll i = 0; i < v[num].size(); i++) {
		ll next = check(v[num][i]);
		if (next) {
			p.push_back(v[num][i]);
			recur(location + 1, next);
			p.pop_back();
		}
	}
	return;
}
int main()
{
	scanf("%lld", &N);
	for (ll i = 1; i <= N; i++){
		scanf("%lld", &B[i]);
		v[i].push_back(B[i] * 2);
		if (B[i] % 3 == 0) v[i].push_back(B[i] / 3);
	}

	for (ll i = 1; i <= N; i++) {
		if (!flag) {
			p.push_back(B[i]);
			recur(1, i);
			p.pop_back();
		}
	}
}
