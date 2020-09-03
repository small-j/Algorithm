#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v[100005];
bool check[100005] = { false };
int D, cnt = 0;
int dfs(int node, int d)
{
    check[node] = true;
    int s = v[node].size(), n = 0, Max = 0;
    for (int i = 0; i < s; i++) {
        if (check[v[node][i]]) continue;
        Max = max(Max, dfs(v[node][i], d + 1));
        n++;
    }
    if (n == 0) Max = d;    
    if (Max - d >= D) cnt++;
        return Max;
}
int main()
{
    int N, S;
    cin >> N >> S >> D;
    for (int i = 0; i < N - 1; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(S, 1);
    cnt -= 1;
    if (cnt < 0) cnt = 0;
    cout << cnt * 2 << endl;
}
