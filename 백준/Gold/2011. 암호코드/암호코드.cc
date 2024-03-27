#include <iostream>
#include <string>

using namespace std;

#define MOD 1000000

string str;
int dp[5010];

void Input() {

	cin >> str;
}

void Solution() {

	if (str[0] == '0') {
		cout << "0\n";
		return;
	}

	int ten = 0, N = str.size();
	dp[0] = dp[1] = 1;

	for (int i = 2; i <= N; i++) {

		if (str[i - 1] != '0') dp[i] = dp[i - 1] % MOD;

		ten = ((str[i - 2] - '0') * 10 + (str[i - 1] - '0'));

		if (ten >= 10 && ten <= 26) dp[i] = (dp[i] + dp[i - 2]) % MOD;
	}

	cout << dp[N] << '\n';
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}