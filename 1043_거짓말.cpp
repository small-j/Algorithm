
//풀이
//bfs

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> v[55];
vector<int> party[55];
queue<int> q;
bool check[55];
void bfs()
{
	while (!q.empty()) {
		int num = q.front();
		q.pop();
		check[num] = true;
		for (int i = 0; i < v[num].size(); i++) 
			if (!check[v[num][i]]) q.push(v[num][i]);
	}
}
int main()
{
	int N, M, truep, cnt = 0;
	scanf("%d%d", &N, &M);
	scanf("%d", &truep);
	for (int i = 0; i < truep; i++) {
		int num;
		scanf("%d", &num);
		q.push(num);
	}
	for (int i = 1; i <= M; i++){
		int num;
		scanf("%d", &num);
		for (int j = 0; j < num; j++) {
			int a;
			scanf("%d", &a);
			party[i].push_back(a);
			if (j > 0) {
				v[party[i][j-1]].push_back(party[i][j]);
				v[party[i][j]].push_back(party[i][j-1]);
			}
		}
	}
	bfs();
	for (int i = 1; i <= M; i++) {
		cnt++;
		for (int j = 0; j < party[i].size(); j++) {
			if (check[party[i][j]]) {
				cnt--;
				break;
			}
		}
	}
	printf("%d\n", cnt);
}
