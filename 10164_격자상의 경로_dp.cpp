#include<iostream>
#include<queue>
using namespace std;
queue<pair<int, int>> q;
int dist[20][20], N, M, K;
int x[2] = { 0, 1 }, y[2] = { 1, 0 };
void bfs(int desx, int desy)
{
	while (!q.empty()) {
		int f = q.front().first, s = q.front().second;
		q.pop();
		for (int i = 0; i < 2; i++) {
			if (desx < f + x[i] || desy < s + y[i])continue;
			if (dist[f + x[i]][s + y[i]] == 0) q.push({ f + x[i], s + y[i] });
			dist[f + x[i]][s + y[i]] += dist[f][s];
		}
	}
	return;
}
int main()
{
	cin >> N >> M >> K;
	q.push({ 1, 1 });
	dist[1][1] = 1;
	int desx = (K + M) / M, desy = (K + M) % M;
	if (desy == 0) {
		desx--;
		desy = M;
	}
	if (K != 0) {
		bfs(desx, desy);
		q.push({ desx, desy });
	}
	bfs(N, M);
	cout << dist[N][M] << "\n";
}
