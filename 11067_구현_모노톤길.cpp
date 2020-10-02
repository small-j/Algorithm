#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		vector<pair<int, int>> map;
		vector<pair<int, int>> v;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			map.push_back({ x, y });
		}
		sort(map.begin(), map.end());

		v.push_back({ -1, 0 });
		for (int i = 0; i < n; i++) {
			if (v[i].first != map[i].first && v[i].second != map[i].second) {
				vector<pair<int, int>> reverse;
				for (int j = i; j < n; j++) {
					reverse.push_back({ map[j].first, map[j].second });
					if (v[i].second == map[j].second) break;
				}
				for (int j = reverse.size() - 1; j >= 0; j--) {
					v.push_back({ reverse[j].first, reverse[j].second });
				}
				i += reverse.size() - 1;
				continue;
			}
			else v.push_back({ map[i].first, map[i].second });
		}

		cin >> m;
		for (int i = 0; i < m; i++) {
			int num;
			cin >> num;
			cout << v[num].first << " " << v[num].second << "\n";
		}
	}
}
