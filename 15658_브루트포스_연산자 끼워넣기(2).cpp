#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int N, A[12], op[4], Max = -1000000000, Min = 1000000000;
int cal(int p, int num, int sum)
{
	if (p == 0) return sum += num;
	else if (p == 1) return sum -= num;
	else if (p == 2) return sum *= num;
	else return sum /= num;
}
void recur(int location, int sum)
{
	if (location == N) {
		Max = max(Max, sum);
		Min = min(Min, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (op[i] <= 0) continue;
		op[i]--;
		recur(location + 1, cal(i, A[location], sum));
		op[i]++;
	}
	return;
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];

	for (int i = 0; i < 4; i++)
		cin >> op[i];

	recur(1, A[0]);

	cout << Max << endl;
	cout << Min << endl;
}
