
// 풀이
// 그리디

#include <iostream>

using namespace std;

int main() {
  int num[3], result[3];
  int n;

  num[0] = 300;
  num[1] = 60;
  num[2] = 10;

  scanf("%i", &n);
  
  for (int i = 0; i < 3; i++) {
      result[i] = n / num[i];
      n -= n / num[i] * num[i];
  }

  if (n == 0) {
    for (int i = 0; i < 3; i++) printf("%i ", result[i]);
  }
  else printf("-1");

  printf("\n");
}
