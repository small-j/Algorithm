#include<iostream>
#include<queue>
using namespace std;
queue<pair<int, int>> q;
int map[1005][1005];
int x[4] = { 0, 0, 1, -1 };
int y[4] = { 1, -1, 0, 0 };
int main()
{
	int X, Y, N;
	cin >> X >> Y >> N;
	X += 500;
	Y += 500;
	for (int i = 0; i < N; i++) {
		int A, B;
		cin >> A >> B;
		map[A + 500][B + 500] = -1;
	}

	q.push({ 500, 500 });
	while (!q.empty()) {
		int xx = q.front().first, yy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (xx + x[i] < 0 || 1000 < xx + x[i] || yy + y[i] < 0 || 1000 < yy + y[i]) continue;
			if (map[xx + x[i]][yy + y[i]] == 0) {
				map[xx + x[i]][yy + y[i]] = map[xx][yy] + 1;
				q.push({ xx + x[i], yy + y[i] });
			}
		}
		if (map[X][Y] != 0) break;
	}
	cout << map[X][Y] << "\n";
}
