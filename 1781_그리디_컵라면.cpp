#include<iostream>
#include<vector>
#include<queue>
#include<functional>
#include<algorithm>
using namespace std;
int main()
{
	int N, sum = 0;
	vector<pair<int, int>> v;
	priority_queue<int, vector<int>, greater<int>> pq;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int deadline, ramyun;
		cin >> deadline >> ramyun;
		v.push_back({ deadline, ramyun });
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		if (pq.size() < v[i].first) pq.push(v[i].second);
		else {
			if (pq.top() < v[i].second) {
				pq.pop();
				pq.push(v[i].second);
			}
		}
	}

	int s = pq.size();
	for (int i = 0; i < s; i++) {
		sum += pq.top();
		pq.pop();
	}
	cout << sum << "\n";
}
