#include<iostream>
#include<string>
using namespace std;
string name[105];
int d[105], m[105], y[105];
int main()
{
	int n, Maxindex = 0, Minindex = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> name[i] >> d[i] >> m[i] >> y[i];
	}



	for (int i = 1; i < n; i++) {
		if (y[Maxindex] > y[i]) Maxindex = i;
		else if(y[Maxindex] == y[i]) {
			if (m[Maxindex] > m[i]) Maxindex = i;
			else if (m[Maxindex] == m[i]) {
				if (d[Maxindex] > d[i]) Maxindex = i;
			}
		}

		if (y[Minindex] < y[i]) Minindex = i;
		else if (y[Minindex] == y[i]) {
			if (m[Minindex] < m[i]) Minindex = i;
			else if (m[Minindex] == m[i]) {
				if (d[Minindex] < d[i]) Minindex = i;
			}
		}
	}

	cout << name[Minindex] << endl;
	cout << name[Maxindex] << endl;
}
