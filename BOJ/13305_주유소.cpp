
// 풀이
// 그리디

#include <iostream>

using namespace std;

long long calcOilPrice(int N, long long *road, long long *priceOfOil);

long long road[100005], priceOfOil[100005];

int main() {
  int N;
  
  scanf("%i", &N);
  for (int i = 0; i < N - 1; i++) scanf("%lld", &road[i]);
  for (int i = 0; i < N; i++) scanf("%lld", &priceOfOil[i]);
  
  printf("%lld\n", calcOilPrice(N, road, priceOfOil));
}

long long calcOilPrice(int N, long long *road, long long *priceOfOil) {
  long long price = priceOfOil[0];
  long long roadPrice = 0;
  
  for (int i = 0; i < N-1; i++) {
    roadPrice += road[i] * price;
    if (price > priceOfOil[i + 1]) price = priceOfOil[i + 1];
  }

  return roadPrice;
}
