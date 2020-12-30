
//풀이
//정렬, 두 포인터

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool desc(int a, int b)
{
	return a > b;
}
int main()
{
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		vector<int> n;
		vector<int> m;
		cin >> N >> M;

		for (int i = 0; i < N; i++) {
			int num;
			cin >> num;
			n.push_back(num);
		}
		for(int i = 0; i < M; i++) {
			int num;
			cin >> num;
			m.push_back(num);
		}

		sort(n.begin(), n.end(), desc);
		sort(m.begin(), m.end(), desc);

		int num = 0, cnt = 0;
		for (int i = 0; i < n.size(); i++) {
			for (int j = num; j < m.size(); j++) {
				if (n[i] > m[j]) {
					cnt += m.size() - j;
					num = j;
					break;
				}
			}
		}
		cout << cnt << "\n";
	}
}
