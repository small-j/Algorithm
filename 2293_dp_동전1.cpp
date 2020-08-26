#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n, k;
	int coin[105] = { 0 }, money[10005] = { 0 }, pmoney[10005] = { 0 };
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &coin[i]);

	sort(coin, coin + n);
	for (int i = 0; i < n; i++)
	{
		int cnt = 0;
		for (int j = 0; j <= k; j++)
		{
			if (i == 0)
			{
				if (j % coin[i] == 0) pmoney[j] = 1;
			}
			else
			{
				if (j < coin[i]) pmoney[j] = money[j];
				else
				{
					pmoney[j] = money[j] + pmoney[cnt];
					cnt++;
				}
			}
		}
		for (int j = 0; j <= k; j++)
			money[j] = pmoney[j];
	}
	printf("%d\n", money[k]);
}
