
//풀이
//그리디, 정렬

#include<iostream>
#include<vector>
using namespace std;
vector<pair<int, int>> v;
int main()
{
	int N, sum = 0;
	scanf("%d", &N);
	while (N--) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (v.size() == 0) {
			v.push_back({ x, y });
			continue;
		}
		if (v[v.size() - 1].first <= x && x <= v[v.size() - 1].second) {
			if (v[v.size() - 1].second < y) v[v.size() - 1].second = y;
		}
		else v.push_back({ x, y });
	}
	for (int i = 0; i < v.size(); i++)
		sum += v[i].second - v[i].first;
	printf("%d\n", sum);
}
