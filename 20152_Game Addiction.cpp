
//풀이
//다이나믹 프로그래밍

#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
queue<pair<ll, ll>> q;
ll map[35][35], acc[35][35], H, N, cnt = 0;
ll x[4] = { 0, 0, 1, -1 }, y[4] = { 1, -1, 0, 0 };
void bfs()
{
	while (!q.empty()) {
		ll f = q.front().first, s = q.front().second;
		q.pop();
		for (ll i = 0; i < 4; i++) {
			if (f + x[i] < 0 || s + y[i] < 0 || f + x[i] < s + y[i] || (H < f + x[i] && N < f + x[i])) continue;
			if (map[f + x[i]][s + y[i]] < map[f][s] + 1) continue;
			map[f + x[i]][s + y[i]] = map[f][s] + 1;
			if (f + x[i] == N && s + y[i] == N) {
				acc[f + x[i]][s + y[i]] += acc[f][s];
				continue;
			}
			if (acc[f + x[i]][s + y[i]] == 0) {
				q.push({ f + x[i], s + y[i] });
			}
			acc[f + x[i]][s + y[i]] += acc[f][s];
		}
	}
}
int main()
{
	cin >> H >> N;
	if (H == N) cout << 1 << "\n";
	else {
		for (ll i = 0; i < 35; i++)
			fill(map[i], map[i] + 35, 1000000);
		map[H][H] = 0;
		acc[H][H] = 1;
		q.push({ H, H });
		bfs();
		cout << acc[N][N] << "\n";
	}
}
