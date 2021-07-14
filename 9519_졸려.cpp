
//풀이
//수학, 구현, 문자열

#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int X, x, cnt = 0;
	char word[31005];
	char c[31005], check[31005];
	scanf("%d", &X);
	scanf("%s", word);
	int len = strlen(word);
	for (int i = 0; i < len; i++)
		c[i] = word[i];

	while (strncmp(word, check, len))
	{
		int k = 0;
		if (len % 2 == 0)
		{
			for (int i = 0; i < (len / 2); i++)
			{
				check[k] = c[i];
				check[k + 1] = c[len - i - 1];
				k += 2;
			}
		}
		else
		{
			for (int i = 0; i <= (len / 2); i++)
			{
				check[k] = c[i];
				if (i == len - i - 1) break;
				check[k + 1] = c[len - i - 1];
				k += 2;
			}
		}
		for (int i = 0; i < len; i++)
			c[i] = check[i];
		cnt++;
	}
	x = X % cnt;
	for (int i = 0; i < x; i++)
	{
		int k = 0;
		int num = 0;
		for (int j = 0; j < len; j+=2)
		{
			check[k] = c[j];
			k++;
		}
		if (len % 2 == 0) num = len - 1;
		else num = len - 2;
		for (int j = num; j >= 1; j-=2)
		{
			check[k] = c[j];
			k++;
	 	}

		for (int i = 0; i < len; i++)
			c[i] = check[i];
	}
	for (int i = 0; i < len; i++)
		printf("%c", check[i]);
	return 0;
}
