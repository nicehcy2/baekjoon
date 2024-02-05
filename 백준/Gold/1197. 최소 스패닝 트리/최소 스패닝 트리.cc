#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int V, E;
vector<pair<int, int>> v[100001]; // {value, end}
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
bool visited[10001];
int ans = 0;

void Solution() {

    // 시작 정점
    int startVertex = 1;
    pq.push({ 0, startVertex });

    while(!pq.empty()) {

        int curVertex = pq.top().second;
        int curValue = pq.top().first;
        pq.pop();

        if (visited[curVertex]) continue;

        ans += curValue;

        visited[curVertex] = true;

        for (int j = 0; j < v[curVertex].size(); j++) {

            if (!visited[v[curVertex][j].second])
                pq.push({ v[curVertex][j].first, v[curVertex][j].second });
        }
    }

    cout << ans << '\n';
}

void Input() {
    int start, end, value;

    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        cin >> start >> end >> value;

        v[start].push_back({ value, end });
        v[end].push_back({ value, start });
    }
}

int main() {
    Input();
    Solution();

    return 0;
}