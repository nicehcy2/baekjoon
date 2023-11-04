#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
pair<int, int> lesson[200001];

void Input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		lesson[i] = { start, end };
	}
}

void Solution() {
	int classNum = 1;

	priority_queue<int, vector<int>, greater<int>> pq;
	sort(lesson, lesson + n);

	pq.push(lesson[0].second);
	for (int i = 1; i < n; i++) {
		int checkEnd = pq.top();

		if (checkEnd > lesson[i].first) {
			pq.push(lesson[i].second);
			classNum++;
		}
		else {
			pq.push(lesson[i].second);
			pq.pop();
		}
	}

	cout << classNum << '\n';

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}