#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
typedef pair<int, int> p;
p Move[8] = { {2, 1}, {2, -1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {1, -2}, {-1, -2} };
int main()
{
	int t;
	cin >> t;
	while (t--) {
		queue<p> q;
		int map[305][305];
		int x, y, dx, dy, limit;
		cin >> limit >> x >> y >> dx >> dy;
		memset(map, 0, sizeof(map));
		if (x == dx && y == dy) {
			cout << 0 << "\n";
			continue;
		}
		q.push({ x, y });
		while (!q.empty()) {
			for (int i = 0; i < 8; i++) {
				int f = q.front().first + Move[i].first;
				int s = q.front().second + Move[i].second;
				if (f < 0 || limit <= f || s < 0 || limit <= s || map[f][s] != 0) continue;
				if (f == x && s == y) continue;
				if (f == dx && s == dy) {
					map[f][s] = map[q.front().first][q.front().second] + 1;
					cout << map[f][s] << "\n";
					break;
				}
				q.push({ f, s });
				map[f][s] = map[q.front().first][q.front().second] + 1;
			}
			q.pop();
			if (map[dx][dy] != 0) break;
		}
	}
}
