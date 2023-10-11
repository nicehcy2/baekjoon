#include <iostream>
#include <vector>;
#include <algorithm>
#include <utility>

#define INF 2100000000
#define MAX 501

using namespace std;

int n, m;
vector<pair<int, pair<int, int>>> edges;
long long dis[501];

void Input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({ a, {b, c} });
	}
}

bool bellmanFord(int start) {
	dis[start] = 0;
	int from, to, value;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			from = edges[j].first;
			to = edges[j].second.first;
			value = edges[j].second.second;

			if (dis[from] == INF) {
				continue;
			}


			if (dis[to] > dis[from] + value) {
				dis[to] = dis[from] + value;


				if (i == n) {
					return true;
				}
			}
		}
	}

	return false;
}

void Solution() {
	for (int i = 0; i < 501; i++) {
		dis[i] = INF;
	}

	bool negativeCycle = bellmanFord(1);

	if (negativeCycle) {
		cout << "-1\n";
	}
	else {
		for (int i = 2; i <= n; i++) {
			if (dis[i] == INF) {
				cout << "-1\n";
			}
			else {
				cout << dis[i] << '\n';
			}
 		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}