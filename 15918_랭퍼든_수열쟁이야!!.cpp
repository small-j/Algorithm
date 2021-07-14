
//풀이
//백트래킹

#include<iostream>
using namespace std;
int n, x, y, seq[25], cnt = 0;
bool check[13];
void recur(int location) 
{
	if (location == n) {
		cnt++;
		return;
	}
	int num;
	for (int j = 1; j <= n * 2; j++) {
		if (seq[j] == 0) {
			num = j;
			break;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			if (num + i + 1 <= 2 * n && !seq[num + i + 1]) {
				seq[num] = i;
				seq[num + i + 1] = i;
				check[i] = true;
				recur(location + 1);
				check[i] = false;
				seq[num + i + 1] = 0;
				seq[num] = 0;
			}
		}
	}
}
int main()
{
	scanf("%d%d%d", &n, &x, &y);
	seq[x] = y - x - 1;
	seq[y] = y - x - 1;
	check[y - x - 1] = true;
	recur(1);
	printf("%d\n", cnt);
}
