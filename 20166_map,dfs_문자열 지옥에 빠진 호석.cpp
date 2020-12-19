#include<iostream>
#include<string>
#include<map>
using namespace std;
typedef pair<int, int> p;
p m[8] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1} };
int N, M, K, cnt = 0;
char w[15][15];
map<string, int> strcnt;
void dfs(int x, int y, int deep, string str)
{
	if (w[x][y] != str[deep]) return;
	if (w[x][y] == str[deep] && deep == str.length() - 1) {
		cnt++;
		return;
	}
	for (int i = 0; i < 8; i++) {
		int xx = x + m[i].first;
		int yy = y + m[i].second;
		if (xx == 0) {
			xx += N;
			if (yy == 0) yy += M;
			else if (yy == M + 1) yy = 1;
		}
		else if (xx == N + 1) {
			xx = 1;
			if (yy == 0) yy = M;
			else if (yy == M + 1) yy = 1;
		}
		else if (yy == 0) yy += M;
		else if (yy == M + 1) yy = 1;
		dfs(xx, yy, deep + 1, str);
	}
	return;
}
int main()
{
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			cin >> w[i][j];
	}
	for (int i = 0; i < K; i++) {
		string str;
		cin >> str;
		cnt = 0;
		if (strcnt.find(str) == strcnt.end()) {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= M; j++) {
					dfs(i, j, 0, str);
				}
			}
			strcnt[str] = cnt;
		}
		cout << strcnt[str] << "\n";
		cnt = 0;
	}

}
