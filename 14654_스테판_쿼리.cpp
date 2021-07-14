
//풀이
//구현

#include<iostream>
#include<algorithm>
using namespace std;
int game(int a, int b)
{
	if (a == 3 && b == 1) return 2;
	else if (a == 1 && b == 3) return 1;
	else if (a < b) return 2;
	else if (a > b) return 1;
	else return 3;
}
int main()
{
	int N, A[301], B[301], a = 0, b = 0, before, Max = 0;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	for (int i = 0; i < N; i++) scanf("%d", &B[i]);
	for(int i = 0; i<N; i++) {
		int num = game(A[i], B[i]);
		if (num == 1) {
			a++;
			Max = max(Max, max(a, b));
			b = 0;
			before = 1;
		}
		else if (num == 2) {
			b++;
			Max = max(Max, max(a, b));
			a = 0;
			before = 2;
		}
		else {
			if (before == 1) {
				b++;
				Max = max(Max, max(a, b));
				a = 0;
				before = 2;
			}
			else {
				a++;
				Max = max(Max, max(a, b));
				b = 0;
				before = 1;
			}
		}
	}
	printf("%d\n", Max);
}
