#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
bool visited[201000];
int memo[201000];

class Node {
public:
    int pos;
    int time;

    Node(int p, int t) {
        pos = p;
        time = t;
    }
};

void bfs() {

    queue<Node> q;
    visited[N] = true;
    memo[N] = 0;

    q.push(Node(N, 0));

    while (!q.empty()) {
        int curPos = q.front().pos;
        int curTime = q.front().time;
        q.pop();

        if (curPos == K) {
            cout << curTime << '\n';

            int next = curPos;
            vector<int> route;
            for (int i = 0; i < curTime + 1; i++) {
                route.push_back(next);
                next = memo[next];
            }

            reverse(route.begin(), route.end());
            for (int i = 0; i < route.size(); i++) {
                cout << route[i] << " ";
            }
            cout << '\n';
        }


        if (!visited[curPos * 2] && (curPos * 2) <= 200000 && (curPos * 2) >= 0) {
            q.push(Node(curPos * 2, curTime + 1));
            visited[curPos * 2] = true;
            memo[curPos * 2] = curPos;
        }

        if (!visited[curPos - 1] && (curPos - 1) <= 200000 && (curPos - 1) >= 0) {
            q.push(Node(curPos - 1, curTime + 1));
            visited[curPos - 1] = true;
            memo[curPos - 1] = curPos;
        }

        if (!visited[curPos + 1] && (curPos + 1) <= 200000 && (curPos + 1) >= 0) {
            q.push(Node(curPos + 1, curTime + 1));
            visited[curPos + 1] = true;
            memo[curPos + 1] = curPos;
        }
    }
}

void Solution() {

    bfs();
}

void Input() {

    cin >> N >> K;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    Input();
    Solution();

    return 0;
}