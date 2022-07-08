
//풀이
//그리디

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> number;
char N[100005];

bool desc(int a, int b){ 
  return a > b; 
} 

int main() {
  scanf("%s", N);

  int sum = 0;
  
  for (int i = 0; N[i] != '\0'; i++) {
    int num = int(N[i] - 48);
    number.push_back(num);
    sum += num;
  }

  sort(number.begin(), number.end(), desc);
  

  if (sum % 3 != 0 || number[number.size() - 1] != 0) printf("-1\n");
  else {
      for (int i = 0; i < number.size(); i++) {
      printf("%i", number[i]);
    }
  }
    return 0;
}
