
//풀이
//구현, 정렬

#include<iostream>
using namespace std;
int country[1001][3];
int main()
{
	int N, K, g, s, b, cnt = 1;
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N; i++) {
		int num;
		scanf("%d%d%d%d", &num, &country[i][0], &country[i][1], &country[i][2]);
		if (num == K) {
			g = country[i][0];
			s = country[i][1];
			b = country[i][2];
		}
	}
	for (int i = 1; i <= N; i++) {
		if (country[i][0] > g) cnt++;
		else if (country[i][0] == g && country[i][1] > s) cnt++;
		else if (country[i][0] == g && country[i][1] == s && country[i][2] > b) cnt++;
	}
	printf("%d\n", cnt);
}
