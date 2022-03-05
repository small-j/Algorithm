
// 풀이
// bfs

#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct area {
    int x, y;
};
typedef area area;

bool visited[105][105];
int moveX[4] = { 0, 0, 1, - 1 };
int moveY[4] = { 1, -1, 0, 0 };

int bfs(int startX, int startY, int m, int n, vector<vector<int>> picture) {
    int areaSize = 1;
    int nowColor = picture[startX][startY];
    queue<area> areaQueue;
    
    areaQueue.push({ startX, startY });
    visited[startX][startY] = true;

    while (!areaQueue.empty()) {
        area nowArea = areaQueue.front();
        areaQueue.pop();

        for (int i = 0; i < 4; i++) {
            int x = nowArea.x + moveX[i];
            int y = nowArea.y + moveY[i];

            if (x < 0 || x >= m || y < 0 || y >= n) continue;
            if (picture[x][y] != nowColor || visited[x][y]) continue;
            areaQueue.push({ x, y });
            areaSize++;
            visited[x][y] = true;
        }
    }
    return areaSize;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    for (int i = 0; i < m; i++) fill(visited[i], visited[i] + n, false);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (picture[i][j] != 0 && !visited[i][j]) {
                number_of_area++;
                max_size_of_one_area = max(max_size_of_one_area, bfs(i, j, m, n, picture));
            }
        }
    }

    vector<int> answer = { number_of_area, max_size_of_one_area };
    return answer;
}
