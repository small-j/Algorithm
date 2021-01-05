
//풀이
//정렬

#include<stdio.h>
int main()
{
	int num[3],i;
	int min = 0;
	int cnt = 0;
	for (i = 0; i < 3; i++)
		scanf("%d", &num[i]);
	if (num[0] > 0 && num[0] <= 1000000 && num[1] > 0 && num[1] <= 1000000 && num[2] > 0 && num[2] <= 1000000)
	{
		while (cnt != 2) {
			cnt = 0;
			for (i = 0; i < 2; i++)
			{
				if (num[i] <= num[i + 1]) cnt++;
				else
				{
					min = num[i + 1];
					num[i + 1] = num[i];
					num[i] = min;
				}
			}
		}
		for (i = 0; i < 3; i++)
			printf("%d ", num[i]);
		printf("\n");
	}

}
