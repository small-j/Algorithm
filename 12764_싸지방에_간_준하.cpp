
//풀이
//정렬, 그리디

#include<iostream>
#include<vector>
#include<queue>
#include<functional>
#include<algorithm>
using namespace std;
typedef pair<int, int> p;
priority_queue<p, vector<p>, greater<p>> pq;
priority_queue<int, vector<int>, greater<int>> q;
vector<p> v;
int check[100000];
int main()
{
	int N, cnt = 0, Max = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int P, Q;
		scanf("%d%d", &P, &Q);
		v.push_back({ P, Q });
		q.push(i);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		while (!pq.empty() && pq.top().first < v[i].first) {
			q.push(pq.top().second);
			pq.pop();
		}
		pq.push({ v[i].second, q.top() });
		check[q.top()]++;
		Max = max(Max, q.top());
		q.pop();
	}
	printf("%d\n", Max + 1);

	for (int i = 0; i < Max + 1; i++)
		printf("%d ", check[i]);
}
