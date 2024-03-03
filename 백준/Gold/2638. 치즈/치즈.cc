#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int N, M;

vector<vector<int>> arr;
vector<pair<int, int>> era;
vector<pair<int, int>> boundCheese;

bool visited[101][101];

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

bool checkDelete(int y, int x) {
    int count = 0;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
            if (arr[ny][nx] == 0 && visited[ny][nx]) {
                count++;
            }
        }
    }

    if (count >= 2) return true;
    else return false;
}

void bfs() {
    queue<pair<int, int>> q;
    q.push({ 0, 0 });
    visited[0][0] = true;

    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny >= 0 && ny < N && nx >= 0 && nx < M && !visited[ny][nx]) {
                if (arr[ny][nx] == 0) {
                    visited[ny][nx] = true;
                    q.push({ ny, nx });
                }
                else {
                    visited[ny][nx] = true;
                    boundCheese.push_back({ ny, nx });
                }
            }
        }
    }
}

void Solution() {

    int answer = 0;

    while (true) {

        // 탐색
        bfs();
        //cout << boundCheese.size() << '\n';
        for (int i = 0; i < boundCheese.size(); i++) {
            if (checkDelete(boundCheese[i].first, boundCheese[i].second)) {
                era.push_back({ boundCheese[i].first, boundCheese[i].second });
            }
        }

        if (boundCheese.empty()) {
            break;
        }
        boundCheese.clear();
        memset(visited, 0, sizeof(visited));

        // 삭제

        for (int i = 0; i < era.size(); i++) {
            arr[era[i].first][era[i].second] = 0;
        }
        era.clear();

        answer++;
    }

    cout << answer << '\n';
}

void Input() {

    cin >> N >> M;

    for (int i = 0; i < N; i++) {

        vector<int> lv;
        for (int j = 0; j < M; j++) {
            int num;
            cin >> num;

            lv.push_back(num);
        }

        arr.push_back(lv);
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Input();
    Solution();

    return 0;
}