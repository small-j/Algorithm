#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while (T--) {
		int chemical[3], AB, BC, CA, Max = 0;
		cin >> chemical[0] >> chemical[1] >> chemical[2];
		cin >> AB >> BC >> CA;

		int Min = min(chemical[0], chemical[1]);
		for (int i = 0; i <= Min; i++) {
			int cal[3];
			cal[0] = chemical[0] - i;
			cal[1] = chemical[1] - i;
			cal[2] = chemical[2];
			if (BC < CA) {
				int num = (AB * i) + (CA * min(cal[0], cal[2]));
				cal[2] -= min(cal[0], cal[2]);
				num += BC * min(cal[1], cal[2]);
				Max = max(num, Max);
			}
			else {
				int num = (AB * i) + (BC * min(cal[1], cal[2]));
				cal[2] -= min(cal[1], cal[2]);
				num += CA * min(cal[0], cal[2]);
				Max = max(num, Max);
			}
		}
		cout << Max << endl;
	}
}
