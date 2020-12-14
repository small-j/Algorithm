#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
typedef pair<int, int> p;
vector<p> tree[100005];
bool check[100005];
int Max = 0, MNode;
void bfs(int now, int weight)
{
	check[now] = true;
	if (Max <= weight) {
		Max = weight;
		MNode = now;
	}
	for (int i = 0; i < tree[now].size(); i++) {
		int next = tree[now][i].first;
		if (check[next]) continue;
		bfs(next, weight + tree[now][i].second);
	}
	return;
}
int main()
{
	int N, first, second, fMax;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b, weight;
		cin >> a >> b >> weight;
		tree[a].push_back({ b, weight });
		tree[b].push_back({ a, weight });
	}
	bfs(1, 0);
	
	Max = 0;
	first = MNode;
	memset(check, 0, sizeof(check));
	bfs(first, 0);

	memset(check, 0, sizeof(check));
	second = MNode;
	check[second] = true;
	Max = 0;
	bfs(first, 0);

	fMax = Max;
	memset(check, 0, sizeof(check));
	check[first] = true;
	Max = 0;
	bfs(second, 0);
	
	cout << max(Max, fMax) << "\n";
}
