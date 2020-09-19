#include<iostream>
using namespace std;
int n[100005];
int main()
{
	int N, S;
	cin >> N >> S;
	for (int i = 0; i < N; i++) cin >> n[i];

	int left = 0, right = 0, Min = 1000000000;
	int sum = n[right];
	while (1) {
		if (sum >= S) Min = min(Min, right - left + 1);
		if (sum < S) {
			right++;
			if (right == N) break;
			sum += n[right];
		}
		else {
			if (right == 0) {
				right++;
				sum += n[right];
			}
			sum -= n[left];
			left++;
		}
	}

	if (Min == 1000000000) cout << 0 << endl;
	else cout << Min << endl;
}
