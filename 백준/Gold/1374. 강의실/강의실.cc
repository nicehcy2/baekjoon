#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, num;
pair<int, int> arr[100001];

void Input() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num >> arr[i].first >> arr[i].second;
	}
}

void Solution() {

	sort(arr, arr + N);

	priority_queue<int, vector<int>, greater<int>> pq;

	pq.push(arr[0].second);

	for (int i = 1; i < N; i++) {
		
		if (arr[i].first >= pq.top()) {
			pq.pop();
			pq.push(arr[i].second);
		}
		else pq.push(arr[i].second);
	}

	cout << pq.size() << '\n';
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}