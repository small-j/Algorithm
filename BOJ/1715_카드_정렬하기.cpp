
// 풀이
// 그리디

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main() {
  int n;
  scanf("%i", &n);

  for (int i = 0; i < n; i++) {
    int num;
    scanf("%i", &num);
    pq.push(num);
  }

  if (n == 1) {
    printf("0\n");
    return 0;
  }
  
  int result = 0;
  while(!pq.empty()) {
    int num1 = pq.top();
    pq.pop();
    int num2 = pq.top();
    pq.pop();

    int sum = num1 + num2;
    result += sum;
    if (pq.empty()) break;
    
    pq.push(sum);
  }

  printf("%i\n", result);
  
  return 0;
}
