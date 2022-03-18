
//풀이
//bfs, 그래프

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> p;

queue<int> nodes;
int visited[20005] = { 0 };

int bfs(vector<vector<int>> graph) {
    int Max = 0;

    while (!nodes.empty()) {
        int node = nodes.front();
        nodes.pop();

        for (int i = 0; i < graph[node].size(); i++) {
            int currentNode = graph[node][i];
            if (visited[currentNode]) continue;
            nodes.push(currentNode);
            visited[currentNode] = visited[node] + 1;
            Max = max(Max, visited[currentNode]);
        }
    }

    return Max;
}

int findMostFarNode(int n, int Max) {
    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        if (visited[i] == Max) cnt++;
    }

    return cnt;
}

vector<vector<int>>  makeGraph(vector<vector<int>> edge, int n) {
    vector<vector<int>> graph;
    for (int i = 0; i <= n; i++) graph.push_back({});

    for (int i = 0; i < edge.size(); i++) {
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }

    return graph;
}

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> graph = makeGraph(edge, n);

    nodes.push(1);
    visited[1] = 1;
    int Max = bfs(graph);

    return findMostFarNode(n, Max);
}
