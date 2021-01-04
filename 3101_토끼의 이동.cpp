
//풀이
//수학, 구현

#include<iostream>
#include<vector>
using namespace std;
long long first[200005];
int main()
{
	long long N, K, cnt = 0, num = 0, sum = 1;
	scanf("%lld%lld", &N, &K);
	getchar();

	for (long long i = 0; i < N + (N - 1); i++)
	{
		if (N > i) cnt++;
		else cnt--;
		if ((i + 1) % 2 == 0) num += cnt;
		if (i % 2 == 0)
		{
			num++;
			first[i] = num;
			num += cnt - 1;
		}
		else
		{
			first[i] = num;
			num -= cnt;
		}
		if ((i + 1) % 2 == 0) num += cnt;
	}
	long long x = 0, y = 0;
	cnt = 0;
	for (long long i = 0; i < K; i++)
	{
		char jump;
		scanf("%c", &jump);
		if (jump == 'U')
		{
			if (x + y > N - 1) cnt++;
			x--;
		}
		else if (jump == 'D')
		{
			if (x + y >= N - 1) cnt--;
			x++;
		}
		else if (jump == 'L')
		{
			if (x + y <= N - 1) cnt--;
			y--;
		}
		else if (jump == 'R')
		{
			if (x + y < N - 1) cnt++;
			y++;
		}
		if ((x + y) % 2 == 0) sum += (first[x + y] + cnt);
		else sum += (first[x + y] - cnt);
	}

	printf("%lld\n", sum);
}
