
//풀이
//브루트포스

#include<iostream>
using namespace std;
int box[1005][1005], result[4005];
pair<int, int> direction[2] = { {0, 1}, {-1, 0} };
int dfs(int x, int y, int nowDirection) {
	if (box[x][y] == -1) {
		nowDirection = (nowDirection + 1) % 2;
	}
	int nextX = x + direction[nowDirection].first;
	int nextY = y + direction[nowDirection].second;
	if (box[nextX][nextY] != 0 && box[nextX][nextY] != -1) {
		return box[nextX][nextY];
	}
	return dfs(nextX, nextY, nowDirection);
}
int main()
{
	int N, M, hole = 0;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int num;
			cin >> num;
			box[i][j] = (num == 1 ? -1 : 0);
		}
	}

	for (int i = 1; i <= N; i++) box[i][0] = ++hole;
	for (int i = 1; i <= M; i++) box[N + 1][i] = ++hole;
	for (int i = N; i > 0; i--) box[i][M + 1] = ++hole;
	for (int i = M; i > 0; i--) box[0][i] = ++hole;

	for (int i = 1; i <= N; i++) {
		int arrivalHole = dfs(i, 0, 0);
		result[box[i][0]] = arrivalHole;
		result[arrivalHole] = box[i][0];
	}
	for (int i = 1; i <= M; i++) {
		int arrivalHole = dfs(N + 1, i, 1);
		result[box[N+1][i]] = arrivalHole;
		result[arrivalHole] = box[N + 1][i];
	}
	for (int i = 1; i <= hole; i++) {
		cout << result[i] << " ";
	}
}
