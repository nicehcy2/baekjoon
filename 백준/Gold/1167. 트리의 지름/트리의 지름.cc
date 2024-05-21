#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int V;
vector<pair<int, int>> g[100001];
bool visited[100001];

int diameter, maxDist = 0;

void dfs(int n, int dist) {

    if (maxDist < dist) {
        maxDist = dist;
        diameter = n;
    }
    
    visited[n] = true;

    for (int i = 0; i < g[n].size(); i++) {

        if (!visited[g[n][i].first]) {
            dfs(g[n][i].first, dist + g[n][i].second);
        }
    }
}

void Solution() {

    dfs(1, 0);
    memset(visited, 0, sizeof(visited));
    dfs(diameter, 0);

    cout << maxDist << '\n';
}

void Input() {

    cin >> V;

    for (int i = 1; i <= V; i++) {
        
        int start; cin >> start;

        while (true) {
            int edge, cost;

            cin >> edge;
            if (edge == -1) {
                break;
            }
            cin >> cost;

            g[start].push_back({ edge, cost });
        }
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    Input();
    Solution();

    return 0;
}