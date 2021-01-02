
//풀이
//bfs, brute force

#include<iostream>
#include<algorithm>
using namespace std;
int N, M;
char board[25][25];
pair<int, int> m[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int movecoin(int deep, int x1, int y1, int x2, int y2)
{
	if (deep == 10) return 100000;
	int Min = 100;
	for (int i = 0; i < 4; i++) {
		int flag = 0;
		int mx1 = x1 + m[i].first, my1 = y1 + m[i].second;
		int mx2 = x2 + m[i].first, my2 = y2 + m[i].second;
		if (board[mx1][my1] == '#') {
			mx1 = x1;
			my1 = y1;
		}
		if (board[mx2][my2] == '#') {
			mx2 = x2;
			my2 = y2;
		}
		if ((mx1 == mx2 && my1 == my2) || (mx1 == x1 && my1 == y1 && mx2 == x2 && my2 == y2)) continue;
		if (mx1 < 0 || mx1 >= N || my1 < 0 || my1 >= M) flag++;
		if (mx2 < 0 || mx2 >= N || my2 < 0 || my2 >= M) flag++;
		if (flag == 1) return deep + 1;
		else if (flag == 2) continue;
		Min = min(Min, movecoin(deep + 1, mx1, my1, mx2, my2));
	}
	return Min;
}
int main()
{
	int cnt = 1, x1, y1, x2, y2;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'o' && cnt == 1) {
				cnt++;
				x1 = i;
				y1 = j;
			}
			else if(board[i][j] == 'o') {
				x2 = i;
				y2 = j;
			}
		}
	}
	int num = movecoin(0, x1, y1, x2, y2);
	if (num == 100000 || num == 100) cout << -1 << "\n";
	else cout << num << "\n";
}
