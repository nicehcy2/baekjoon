#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

#define INF 1000000001;

using namespace std;

int n, m, sv, ev;
vector<pair<int, int>> v[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int dist[1001];

void InitAndInput() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;

		v[start].push_back({ cost, end });
	}

	cin >> sv >> ev;
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}
}

void dijkstra(int start) {
	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty()) {
		int curDist = pq.top().first;
		int curNode = pq.top().second;
		pq.pop();
		if (dist[curNode] < curDist) {
			continue;
		}

		for (int i = 0; i < v[curNode].size(); i++) {
			int nxtDist = v[curNode][i].first;
			int nxtNode = v[curNode][i].second;

			if (curDist + nxtDist < dist[nxtNode]) {
				dist[nxtNode] = curDist + nxtDist;
				pq.push({ curDist + nxtDist, nxtNode });
			}
		}
	}
}

void Solution() {
	dijkstra(sv);
	cout << dist[ev] << '\n';
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	InitAndInput();
	Solution();

	return 0;
}