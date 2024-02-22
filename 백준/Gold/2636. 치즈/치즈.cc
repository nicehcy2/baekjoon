#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int arr[101][101];
bool visited[101][101];
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };
int preCnt = 0;

int bfs() {
    int cnt = 0;
    queue<pair<int, int>> q;
    visited[0][0] = true;
    q.push({ 0, 0 });

    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
                if (!visited[ny][nx] && arr[ny][nx] == 0) {
                    q.push({ ny, nx });
                    visited[ny][nx] = true;
                }

                else if (!visited[ny][nx] && arr[ny][nx] == 1) {
                    cnt++;
                    arr[ny][nx] = 0;
                    visited[ny][nx] = true;
                }
            }
        }
    }

    return cnt;
}

void Solution() {
    int time = 0;
    int cnt = 0;

    while (true) {
        int cnt = bfs();

        if (!cnt) {
            break;
        }
        time++;
        preCnt = cnt;
        
        memset(visited, 0, sizeof(visited));
    }

    cout << time << '\n' << preCnt << '\n';
}

void Input() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];

            if (arr[i][j]) {
                preCnt++;
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