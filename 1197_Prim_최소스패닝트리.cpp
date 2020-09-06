#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
using namespace std;
typedef pair<int, int> p;
priority_queue<p, vector<p>, greater<p>> pq;
vector<p> v[10005];
bool check[10005] = { false };
int weight;
void prim()
{
	while (!pq.empty())
	{
		int f = pq.top().first;
		int s = pq.top().second;
		pq.pop();
		if (!check[s])
		{
			for (int i = 0; i < v[s].size(); i++)
				pq.push({ v[s][i].first, v[s][i].second });
			weight += f;
			check[s] = true;
		}
	}
}
int main()
{
	int N, M;
	weight = 0;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		v[a].push_back({ c,b });
		v[b].push_back({ c,a });
	}
	pq.push({ 0,1 });
	prim();
	printf("%d\n", weight);
}
