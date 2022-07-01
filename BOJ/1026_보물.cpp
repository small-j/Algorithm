
// 풀이
// 

#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b);
int calcData(int N, int *A, int *B);

int main() {
    int N, A[55] = {0}, B[55] = {0};
  
  scanf("%i", &N);

  for (int i = 0; i < N; i++) scanf("%i", &A[i]);
  for (int i = 0; i < N; i++) scanf("%i", &B[i]);

    sort(A, A + N);
    sort(B, B + N, compare);

    printf("%i\n", calcData(N, A, B));
    return 0;
}

bool compare(int a, int b) {
  return a > b;
}

int calcData(int N, int *A, int *B) {
  int result = 0;

  for (int i = 0; i < N; i++) result += A[i] * B[i];

  return result;
}
