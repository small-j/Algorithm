#include<iostream>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
map<int, string> m;
int n[100005];
int main()
{
	int N, M, cnt = 0;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		string str;
		int score;
		cin >> str;
		scanf("%d", &score);
		if (m.count(score) == 0) {
			n[cnt] = score;
			m[n[cnt]] = str;
			cnt++;
		}
	}

	sort(n, n + cnt);
	for (int i = 0; i < M; i++) {
		int num;
		scanf("%d", &num);
		int nn = lower_bound(n, n + cnt, num) - n;
		cout << m[n[nn]] << "\n";
	}
}
