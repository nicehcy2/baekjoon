#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N, M;
string dp[101][101];

void Input() {

	cin >> N >> M;
}

string add(string n1, string n2) {

	string res = "";
	int sum = 0;

	reverse(n1.begin(), n1.end());
	reverse(n2.begin(), n2.end());

	if (n1.size() > n2.size()) {
		int t = n1.size() - n2.size();
		for (int i = 0; i < t; i++) {
			n2 += "0";
		}
	}
	else {
		int t = n2.size() - n1.size();
		for (int i = 0; i < t; i++) {
			n1 += "0";
		}
	}

	int size = n1.size() >= n2.size() ? n1.size() : n2.size();

	for (int i = 0; i < size; i++) {
		int total = (n1[i] - '0') + (n2[i] - '0') + sum;

		if (total >= 10) sum = 1;
		else sum = 0;

		res += ((total % 10) + '0');
	}

	if (sum == 1) res += "1";

	reverse(res.begin(), res.end());

	return res;
}

void Solution() {

	dp[0][0] = "1", dp[1][0] = "1", dp[1][1] = "1";
	
	for (int i = 2; i <= N; i++) {

		dp[i][0] = "1", dp[i][i] = "1";

		for (int j = 1; j < i; j++) {

			// 아래 과정을 string을 사용해서 구현해야됨
			// dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];

			dp[i][j] = add(dp[i - 1][j - 1], dp[i - 1][j]);
		}
	}

	cout << dp[N][M] << '\n';
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}