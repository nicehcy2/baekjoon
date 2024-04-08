#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

int N, K;
long long ans = 0;
queue<int> q;
int dx[2] = { -1 , 1 };
unordered_set<int> s;

void BFS() {

	long long dist = 1;

	while (!q.empty()) {

		int size = q.size();

		while (size--) {
			int cx = q.front();
			q.pop();

			for (int i = 0; i < 2; i++) {
				int pos = cx + dx[i];

				if (s.count(pos) < 1) {
					K--;
					s.insert(pos);
					q.push(pos);
					ans += dist;
				}

				if (K == 0) {
					cout << ans << '\n';
					return;
				}
			}
		}
		dist++;
	}
}

void Input() {

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		q.push(num);
		s.insert(num);
	}

	BFS();
}

void Solution() {

	//BFS();
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	//Solution();

	return 0;
}