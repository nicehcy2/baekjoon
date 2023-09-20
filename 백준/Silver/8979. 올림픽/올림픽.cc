#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, k;
vector<pair<long long, int>> rak;

void init() {
	cin >> n >> k;
	
	for (int i = 0; i < n; i++) {
		int num, gold, silver, bronze;
		cin >> num >> gold >> silver >> bronze;
			
		long long score = gold * 1000000000000 + silver * 1000000 + bronze;
		rak.push_back({ score, num });
		
	}
}

void Solution() {
	sort(rak.begin(), rak.end(), greater<pair<long long , int>>());

	for (int i = 0; i < rak.size(); i++) {
		if (rak[i].second == k) {
			int cnt = 0;
			int j = i;
			while (true) {
				if ((rak[j - 1].first == rak[j].first) && j > 0) {
					cnt++;
					j--;
				}
				else {
					break;
				}
			}
			cout << i + 1 - cnt << '\n';
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();
	Solution();

	return 0;
}