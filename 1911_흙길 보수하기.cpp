


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int N, L, start = 0, plank = 0;
	vector<pair<int, int>> poolList;
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		int l, r;
		cin >> l >> r;
		poolList.push_back({ l, r });
	}
	sort(poolList.begin(), poolList.end());
	for (int i = 0; i < N; i++) {
		if (start < poolList[i].first) {
			start = poolList[i].first;
		}
		
		if (poolList[i].second - start <= 0) continue;
		int needPlank = (poolList[i].second - start) / L;
		needPlank += ((poolList[i].second - start) % L != 0) ? 1 : 0;
		plank += needPlank;
		start += needPlank * L;
	}
	cout << plank;
}
