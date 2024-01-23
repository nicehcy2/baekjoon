#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
vector<pair<int, int>> tm;
priority_queue<int> pq;
//priority_queue<int, vector<int>, greater<int>> pq;

void Solution() {
    int ans = 1;

    // 끝나는 시간 기준으로 정렬
    sort(tm.begin(), tm.end(), greater<>());
    pq.push(tm[0].second);

    for (int i = 1; i < N; i++) {
        if (pq.top() >= tm[i].first) {
            pq.pop();
            pq.push(tm[i].second);
        }

        else {
            ans++;
            pq.push(tm[i].second);
        }
    }

    cout << ans << '\n';
}

void Input() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        int start, end;
        cin >> start >> end;

        // 끝나는 시간으로 정렬
        tm.push_back({ end, start });
    }
}

int main() {
    Input();
    Solution();

    return 0;
}