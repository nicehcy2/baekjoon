#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int N, L, R;
int A[51][51];
bool visited[51][51];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int bfs(int y, int x) {
    int isUnited = 0, sum = 0, cnt = 0;
    bool lVisited[51][51];
    memset(lVisited, false, sizeof(lVisited));

    queue<pair<int, int>> q;
    q.push({ y, x });
    visited[y][x] = true;
    lVisited[y][x] = true;

    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny >= 0 && ny < N && nx >= 0 && nx < N && visited[ny][nx] == false) {
                // diff
                int diff = abs(A[ny][nx] - A[cy][cx]);
                if (diff >= L && diff <= R) {
                    isUnited = 1;

                    q.push({ ny, nx });
                    visited[ny][nx] = true;
                    lVisited[ny][nx] = true;

                    sum += A[ny][nx];
                    cnt += 1;
                }
            }
        }
    }

    if (cnt != 0) {
        sum += A[y][x];
        cnt += 1;
    }
    else {
        return 0;
    }

    int avg = sum / cnt;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (lVisited[i][j] == true) {
                A[i][j] = avg;
            }
        }
    }

    /*
    cout << '\n';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << A[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
    */

    return isUnited;
}

void Solution() {
    int day = 0;

    while (true) {
        int cnt = 0;
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j])
                    cnt += bfs(i, j);
            }
        }

        if (cnt == 0) {
            break;
        }

        day++;
    }

    cout << day << '\n';
}

void Input() {
    cin >> N >> L >> R;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
}

int main() {
    Input();
    Solution();

    return 0;
}