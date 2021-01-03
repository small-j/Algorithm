
//풀이
//구현, brute force

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool check[10];
int ningre[10][4][4], Max, n;
char stringre[10][4][4];
vector<int> v;
int coor[16][3] = { {0,0, 0}, {0, 0,1}, {0, 1, 0}, {0, 1,1}, {1,0, 0}, {1, 0,1}, {1, 1, 0}, {1, 1,1}
					,{2,0, 0}, {2, 0,1}, {2, 1, 0}, {2, 1,1}, {3,0, 0}, {3, 0,1}, {3, 1, 0}, {3, 1,1} };
void change(int num1[5][5], int num2[5][5], char str1[5][5], char str2[5][5])
{
	for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) num2[i][j] = num1[i][j];
	for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) str2[i][j] = str1[i][j];
	return;
}
void fill0(int num[5][5], char str[5][5])
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			num[i][j] = 0;
			str[i][j] = 'W';
		}
	}
}
void spin(int nn, int num, int num1[4][4], char str[4][4])
{
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++) {
			num1[i][j] = ningre[v[nn]][i][j];
			str[i][j] = stringre[v[nn]][i][j];
		}
	}
	int cnt = 0, num2[4][4] = { 0 }, str2[4][4] = {'\0'};
	while (cnt < coor[num][0]) {
		int z = 3;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				num2[j][z] = num1[i][j];
				str2[j][z] = str[i][j];
			}
			z--;
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				num1[i][j] = num2[i][j];
				str[i][j] = str2[i][j];
			}
		}
		cnt++;
	}
	return;
}
void pp(int num, int num1[5][5], int num2[4][4], char str1[5][5], char str2[4][4])
{
	int x = coor[num][1];
	int y = coor[num][2];
	int z = 4 + x;
	int q = 4 + y;
	int xx = 0, yy = 0;
	for (int i = x; i < z; i++){
		for (int j = y; j < q; j++){
			if (num1[i][j] + num2[xx][yy] < 0) num1[i][j] = 0;
			else if (9 < num1[i][j] + num2[xx][yy]) num1[i][j] = 9;
			else num1[i][j] = num2[xx][yy] + num1[i][j];
			if(str2[xx][yy] != 'W') str1[i][j] = str2[xx][yy];
			yy++;
		}
		yy = 0;
		xx++;
	}
	return;
}
void recur(int location)
{
	if (location == 3)
	{
		int nummap[5][5], ii = 0;
		char strmap[5][5];

		fill0(nummap, strmap);
		for (int i = 0; i < 16; i++){
			int num1[5][5], num11[4][4];
			char str1[5][5], str11[4][4];
			fill0(num1, str1);
			change(nummap, num1, strmap, str1);
			spin(ii, i, num11, str11);
			pp(i, num1, num11, str1, str11);
			for (int j = 0; j < 16; j++){
				ii++;
				int num2[5][5], num22[4][4];
				char str2[5][5], str22[4][4];
				fill0(num2, str2);
				change(num1, num2, str1, str2);
				spin(ii, j, num22, str22);
				pp(j, num2, num22, str2, str22);
				for (int k = 0; k < 16; k++){
					ii++;
					int num3[5][5], num33[4][4];
					char str3[5][5], str33[4][4];
					fill0(num3, str3);
					change(num2, num3, str2, str3);
					spin(ii, k, num33, str33);
					pp(k, num3, num33, str3, str33);

					int R = 0, B = 0, G = 0, Y = 0;
					for (int r = 0; r < 5; r++){
						for (int h = 0; h < 5; h++) {
							if (str3[r][h] == 'R') R += num3[r][h];
							else if (str3[r][h] == 'B') B += num3[r][h];
							else if (str3[r][h] == 'G') G += num3[r][h];
							else if (str3[r][h] == 'Y') Y += num3[r][h];
						}
					}
					Max = max(Max, R * 7 + B * 5 + G * 3 + Y * 2);
					ii--;
				}
				ii--;
			}
		}
	}
	for (int i = 0; i < n; i++){
		if (!check[i]){
			check[i] = true;
			v.push_back(i);
			recur(location + 1);
			v.pop_back();
			check[i] = false;
		}
	}
	return;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		for (int k = 0; k < 4; k++)
			for (int j = 0; j < 4; j++)
				scanf("%d", &ningre[i][k][j]);
		for (int k = 0; k < 4; k++){
			getchar();
			char c;
			for (int j = 0; j < 4; j++){
				scanf("%c", &stringre[i][k][j]);
				if(j != 3) scanf("%c", &c);
			}
		}
	}
	recur(0);
	printf("%d\n", Max);
}
