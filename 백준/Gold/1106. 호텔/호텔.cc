#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int C, N;
vector<pair<int, int>> v;
int dp[100001];

void Solution() {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 1; j < 100001; j++) {
			if (j - v[i].first >= 0) {
				dp[j] = max(dp[j], dp[j - v[i].first] + v[i].second);
			}
		}
	}

	for (int i = 1; i <= 100001; i++)
	{
		if (dp[i] >= C)
		{
			cout << i << '\n';
			break;
		}
	}
}

void Input() {
	int m, h;
	cin >> C >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> m >> h;

		v.push_back({ m, h });
	}
}

int main() {
	Input();
	Solution();

	return 0;
}