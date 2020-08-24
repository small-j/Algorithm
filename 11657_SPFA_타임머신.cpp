#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
long long INF = 1e9, dist[505];
bool check[505] = { false };
int cyclecheck[505];
vector<pair<int, long long>> bus[505];
bool SPFA(int N)
{
	queue<int> q;
	fill(dist, dist + N + 1, INF);
	q.push(1);
	check[1] = true;
	dist[1] = 0;
	cyclecheck[1]++;
	while (!q.empty()) {
		int f = q.front();
		int s = bus[f].size();
		q.pop();
		check[f] = false;
		for (int i = 0; i < s; i++) {
			if (dist[bus[f][i].first] > dist[f] + bus[f][i].second) {
				dist[bus[f][i].first] = dist[f] + bus[f][i].second;
				if (!check[bus[f][i].first]) {
					q.push(bus[f][i].first);
					check[bus[f][i].first] = true;
					cyclecheck[bus[f][i].first]++;
					if (cyclecheck[bus[f][i].first] >= N) {
						return true;
					}
				}
			}
		}
	}
	return false;
}
int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		long long C;
		cin >> A >> B >> C;
		bus[A].push_back({ B, C });
	}
	if (SPFA(N)) cout << "-1\n";
	else {
		for (int i = 2; i <= N; i++) {
			if (dist[i] >= INF) cout << -1 << "\n";
			else cout << dist[i] << "\n";
		}
	}
}
