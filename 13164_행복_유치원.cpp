
//풀이
//그리디, 정렬

#include<iostream>
#include<algorithm>
using namespace std;
int arr[300005], p[300005];
int main()
{
	int N, K, sum = 0;
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	for (int i = 1; i < N; i++)
		p[i - 1] = arr[i] - arr[i - 1];
	sort(p, p + N - 1);
	for (int i = 0; i < N - K; i++) sum += p[i];
	printf("%d\n", sum);
}
