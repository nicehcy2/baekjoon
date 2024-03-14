#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Input();
void Solution();

int T, N;
vector<int> v, visited;

void Input() {

	cin >> T;
	while (T--) {
		
		cin >> N;
		v.clear();
		visited.clear();

		for (int i = 0; i < N; i++) {
			int num; cin >> num;
			v.push_back(num);
			visited.push_back(false);
		}

		Solution();
	}
}

void Solution() {

	sort(v.begin(), v.end());
	vector<int> rv;

	for (int i = 0; i < N; i += 2) {
		rv.push_back(v[i]);
		visited[i] = true;
	}

	for (int i = N - 1; i >= 0; i--) {
		if (!visited[i]) {
			rv.push_back(v[i]);
			visited[i] = true;
		}
	}

	rv.push_back(v[0]);
	int max = 0;
	for (int i = 1; i < rv.size(); i++) {
		if (abs(rv[i] - rv[i - 1]) > max) {
			max = abs(rv[i] - rv[i - 1]);
		}
	}
	
	cout << max << '\n';
}

int main() {
	
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	Input();
	//Solution();

	return 0;
}