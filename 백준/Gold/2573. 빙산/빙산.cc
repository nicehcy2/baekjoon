#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int N, M;   
int arr[301][301];
bool visited[301][301];
vector<pair<int, int>> iceberg;
vector<int> adjacency;

int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };

void checkAd() {

    for (int i = 0; i < iceberg.size(); i++) {

        int cnt = 0;
        for (int d = 0; d < 4; d++) {
            int ny = iceberg[i].first + dy[d];
            int nx = iceberg[i].second + dx[d];

            if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
                if (arr[ny][nx] == 0) {
                    cnt++;
                }
            }
        }

        adjacency.push_back(cnt);
    }
}

void bfs(int y, int x) {

    visited[y][x] = true;
    queue<pair<int, int>> q;
    q.push({ y, x });

    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
                if (!visited[ny][nx] && arr[ny][nx] != 0) {
                    q.push({ ny, nx });
                    visited[ny][nx] = true;
                }
            }
        }
    }
}

void Solution() {

    int ans = 0, year = 0;
    
    while (true) {
        
        int cnt = 0;

        iceberg.clear();
        adjacency.clear();
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (arr[i][j]) {
                    iceberg.push_back({ i, j });
                }
            }
        }

        // 뺴야되는 수 계산
        checkAd();

        // 진짜 뺀다
        for (int i = 0; i < iceberg.size(); i++) {
            int cy = iceberg[i].first;
            int cx = iceberg[i].second;
            int sea = adjacency[i];

            arr[cy][cx] -= sea;
            if (arr[cy][cx] < 0) {
                arr[cy][cx] = 0;
            }
        }

        // 분리 되어있는 지 확인
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!visited[i][j] && arr[i][j] != 0) {
                    bfs(i, j);
                    cnt++;
                }
            }
        }

        year++;

        if (cnt > 1) {
            break;
        }
        else if (cnt == 0) {
            cout << "0\n";
            return;
        }
    }

    cout << year << '\n';
}

void Input() {

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];

            if (arr[i][j]) {
                iceberg.push_back({ i, j });
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Input();
    Solution();

    return 0;
}