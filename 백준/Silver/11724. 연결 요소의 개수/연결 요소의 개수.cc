#include <iostream>
#include <vector>

using namespace std;

bool visited[1001];
vector<int> g[1001];
int N, M;

void dfs(int node) {

    visited[node] = true;

    for (int i = 0; i < g[node].size(); i++) {
        if (!visited[g[node][i]]) {
            dfs(g[node][i]);
        }
    }
}

void Solution() {

    int ans = 0;

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            dfs(i);
            ans++;
        }
    }

    cout << ans << '\n';
}

void Input() {

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        
        int start, end; cin >> start >> end;
        g[start].push_back(end);
        g[end].push_back(start);
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