
//풀이
//구현, 

#include<iostream>
#include<string.h>
using namespace std;
bool check[11];
int N, r[11], Min = 1e9, len[11];
char str[10][105];
void recur(int location)
{
	if (location == N) {
		int cnt = len[r[0]];
		for (int i = 1; i < N; i++) {
			char c = str[r[i- 1]][strlen(str[r[i-1]]) - 1];
			if (c != str[r[i]][0]) cnt++;
			cnt += len[r[i]];
		}
		if(cnt < Min) Min = cnt;
	}
	for (int i = 0; i < N; i++) {
		if (!check[i]) {
			r[location] = i;
			check[i] = true;
			recur(location + 1);
			check[i] = false;
			r[location] = 0;
		}
	}
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%s", str[i]);
	for (int i = 0; i < N; i++) {
		char c = str[i][0];
		int cnt = 0;
		for (int j = 0; j < strlen(str[i]); j++)
			if (c != str[i][j]) {
				cnt++;
				c = str[i][j];
			}
		len[i] = cnt;
	}
	recur(0);
	printf("%d\n", Min);
}
