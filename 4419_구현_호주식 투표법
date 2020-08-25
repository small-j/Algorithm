#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v[21];
string name[21];
bool del[21] = { true };
int vote[1005][21];
int main()
{
	int n, f, total = 0;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		getline(cin, name[i]);
	}

	while (cin >> f) {
		total++;
		vote[total][1] = f;
		for (int i = 2; i <= n; i++)
			cin >> vote[total][i];
		v[f].push_back(total);
		del[f] = false;
	}

	while (1) {
		int Min = 1e9, Max = 0, num;
		for (int i = 1; i <= n; i++) {
			if (del[i]) continue;
			Min = min(Min, (int)v[i].size());
			Max = max(Max, (int)v[i].size());
			if (Max == v[i].size()) num = i;
		}
		if (Max == Min) {
			for (int i = 1; i <= n; i++)
				if (!del[i]) cout << name[i] << endl;
			break;
		}
		if (total / 2 < Max) {
			cout << name[num] << endl;
			break;
		}
		for (int i = 1; i <= n; i++) {
			if (Min == v[i].size()) del[i] = true;
		}
		for(int i = 1; i<=n; i++){
			if (Min != v[i].size()) continue;
			for (int j = 0; j < Min; j++) {
				int voteindex = v[i][j];
				for (int k = 2; k <= n; k++) {
					if (!del[vote[voteindex][k]]) {
						v[vote[voteindex][k]].push_back(voteindex);
						break;
					}
				}
			}
			while (v[i].size() != 0) v[i].pop_back();
		}
	}
}
