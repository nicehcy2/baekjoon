#include <iostream>
#include <cstring>

using namespace std;

int W, H;
int arr[51][51];
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

bool visited[51][51];

void dfs(int y, int x) {
    visited[y][x] = true;

    for (int i = 0; i < 8; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny >= 0 && ny < H && nx >= 0 && nx < W) {
            if (visited[ny][nx] == false && arr[ny][nx] == 1) {
                visited[ny][nx] = true;
                dfs(ny, nx);
            }
        }
    }
}

void Solution() {
    int cnt = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (visited[i][j] == false && arr[i][j] == 1) {
                cnt++;
                dfs(i, j);
            }
        }
    }

    cout << cnt << '\n';
}

void Input() {

    while (true) {
        cin >> W >> H;

        if (W == 0 && H == 0) break;

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> arr[i][j];
            }
        }

        memset(visited, 0, sizeof(visited));
        Solution();
    }
}

int main() {
    Input();
    //Solution();

    return 0;
}