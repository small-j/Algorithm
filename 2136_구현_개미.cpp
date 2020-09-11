#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
vector<pair<int, int> > ant;
vector<int> Left;
vector<int> Right;
int main()
{
	int N, L;
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		if (x == 0 || x == L) {
			if (x < 0) Right.push_back(0);
			else Left.push_back(0);
		}
		else if (x < 0) Left.push_back(abs(x));
		else Right.push_back(L - x);
		ant.push_back({abs(x), i });
	}
	sort(ant.begin(), ant.end());
	sort(Left.begin(), Left.end());
	sort(Right.begin(), Right.end());
	for (int i = 0; i < Left.size(); i++)
		ant[i].first = Left[i];
	for (int i = 0; i < Right.size(); i++)
		ant[N - i - 1].first = Right[i];
	sort(ant.begin(), ant.end());

	cout << ant[N - 1].second + 1 << " " << ant[N-1].first << endl;
}
