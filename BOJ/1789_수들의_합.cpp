
// 풀이
// 그리디

#include <iostream>

typedef long long ll;
int main() {
  ll S;
  scanf("%lld", &S);

  ll sum = 0, count = 1;
  
  while(sum < S) {
    sum += count;
    if (sum > S) printf("%lld\n", count - 1);
    else if (sum == S) printf("%lld\n", count);
    count++;
  }
  
  return 0;
}
