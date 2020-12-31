
//풀이
//수학, dynamic programming

#include<iostream>
using namespace std;
int D, K, f, s;
void share(int A, int B, int location)
{
	if (A < 1 || A >= B) return;
	if (location == D - 1)
	{
		f = A;
		s = B;
		return;
	}
	share(B - A, A, location + 1);
	return;
}
int main()
{
	scanf("%d%d", &D, &K);

	for (int j = K - 1; j >= 1; j--)
	{
		share(j, K, 1);
		if (f != 0 && s != 0) break;
	}
	printf("%d\n%d\n", f, s);
}
