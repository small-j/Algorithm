#include<iostream>
#include<algorithm>
using namespace std;
int map[105][105], cnt = 0;
bool check[105][105];
int movedomino[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int main()
{
	int N, M, R;
	cin >> N >> M >> R;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> map[i][j];
	for(int i = 0; i<R; i++) {
		int X, Y, d, Max = 0;
		char D;
		cin >> X >> Y >> D;
		if (D == 'E') d = 0;
		else if (D == 'W') d = 1;
		else if (D == 'S') d = 2;
		else d = 3;
		Max = map[X][Y];
		if (!check[X][Y]) {
			while (Max > 0) {
				if (X < 1 || X > N || Y < 1 || Y > M) break;
				if (!check[X][Y]) {
					Max = max(Max, map[X][Y]);
					cnt++;
				}
				check[X][Y] = true;
				X += movedomino[d][0];
				Y += movedomino[d][1];
				Max--;
			}
		}
		cin >> X >> Y;
		check[X][Y] = false;
	}

	cout << cnt << "\n";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (!check[i][j]) cout << "S ";
			else cout << "F ";
		}
		cout << "\n";
	}
}
