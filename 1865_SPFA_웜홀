#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int INF = 1e9;
vector<pair<int,int>> road[505];
bool SPFA(int N, int index)
{
	queue<int> q;
	bool check[505];
	int cyclecheck[505], dist[505];
	fill(dist, dist + N + 1, INF);
	fill(check, check + N + 1, false);
	memset(cyclecheck, 0, sizeof(cyclecheck));
	q.push(index);
	check[index] = true;
	dist[index] = 0;
	cyclecheck[index]++;
	while (!q.empty()) {
		int f = q.front();
		int s = road[f].size();
		q.pop();
		check[f] = false;
		for (int i = 0; i < s; i++) {
			if (dist[road[f][i].first] > dist[f] + road[f][i].second) {
				dist[road[f][i].first] = dist[f] + road[f][i].second;
				if (!check[road[f][i].first]) {
					q.push(road[f][i].first);
					check[road[f][i].first] = true;
					cyclecheck[road[f][i].first]++;
					if (cyclecheck[road[f][i].first] >= N) {
						return false;
					}
				}
			}
		}
	}
	return true;
}
int main()
{
	int TC;
	cin >> TC;
	while (TC--) {
		int N, M, W;
		bool flag = false;
		cin >> N >> M >> W;
		for (int i = 0; i < M; i++) {
			int S, E, T;
			cin >> S >> E >> T;
			road[S].push_back({ E, T });
			road[E].push_back({ S,T });
		}
		for (int i = 0; i < W; i++) {
			int S, E, T;
			cin >> S >> E >> T;
			road[S].push_back({ E, -T });
		}
		for (int i = 1; i <= N; i++) {
			if (!SPFA(N, i)) {
				flag = true;
				break;
			}
		}
		if (flag) cout << "YES\n";
		else cout << "NO\n";
		for (int i = 1; i <= N; i++)
			while (road[i].size() != 0)road[i].pop_back();
	}
}
