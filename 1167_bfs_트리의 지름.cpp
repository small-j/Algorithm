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
	if (Max < weight) {
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
	int V;
	cin >> V;
	for (int i = 0; i < V; i++) {
		int node, next, weight;
		cin >> node >> next;
		while (next != -1) {
			cin >> weight;
			tree[node].push_back({ next, weight });
			cin >> next;
		}
	}
	bfs(1, 0);
	Max = 0;
	memset(check, 0, sizeof(check));
	bfs(MNode, 0);
	cout << Max << "\n";
}
