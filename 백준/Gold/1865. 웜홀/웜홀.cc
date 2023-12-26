#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>

#define INF 1000000000

using namespace std;

int TC, N, M, W, S, E, T;

struct Edge {
	int s, e, t;
};

void Solution(vector<Edge> edges) {
	vector<int> dist(N + 1, INF);
	dist[1] = 0;

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < edges.size(); j++) {
			int from = edges[j].s;
			int to = edges[j].e;
			int cost = edges[j].t;

			if (dist[to] > dist[from] + cost) {
				dist[to] = dist[from] + cost;
			}
		}
	}
	for (int j = 0; j < edges.size(); j++) {
		int from = edges[j].s;
		int to = edges[j].e;
		int cost = edges[j].t;

		if (dist[to] > dist[from] + cost) {
			cout << "YES\n";
			return;
		}
	}

	cout << "NO\n";
}

void Input() {
	cin >> TC;

	while (TC--) {
		cin >> N >> M >> W;

		vector<Edge> edges;

		for (int i = 0; i < M; i++) {
			cin >> S >> E >> T;
			edges.push_back({ S, E, T });
			edges.push_back({ E, S, T });
		}
		for (int i = 0; i < W; i++) {
			cin >> S >> E >> T;
			edges.push_back({ S, E, -T });
		}

		Solution(edges);
	}
}

int main() {
	Input();

	return 0;
}