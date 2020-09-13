#include<iostream>
#include<cstring>
using namespace std;
void checkNum(int num, bool check[10]) 
{
	int gob = 10;
	
	while (num > 0) {
		int n = (num % gob) / (gob / 10);
		check[n] = false;
		num -= (num % gob);
		gob *= 10;
	}
}
int main()
{
	int T, cnt = 1;
	cin >> T;
	while (cnt <= T) {
		int N;
		bool check[10];
		memset(check, 1, sizeof(check));
		cin >> N;
		int num = N;
		if (N == 0) {
			cout << "Case #" << cnt << ": INSOMNIA" << endl;
			cnt++;
			continue;
		}
		while (1) {
			bool flag = false;
			checkNum(num, check);
			for (int i = 0; i < 10; i++) {
				if (check[i]) {
					flag = true;
					break;
				}
			}
			if (!flag) {
				cout << "Case #" << cnt << ": " << num << endl;
				break;
			}
			num += N;
		}
		cnt++;
	}
}
