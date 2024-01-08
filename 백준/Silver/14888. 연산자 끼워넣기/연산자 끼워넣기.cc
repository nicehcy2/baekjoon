#include <iostream>
#include <vector>

using namespace std;

#define INF 1000000000

int N, minNum = INF, maxNum = -INF, opSum;
vector<int> num, oper;

void dfs(int cnt, int cal, vector<int> op) {
	if (cnt == opSum) {
		if (cal > maxNum) {
			maxNum = cal;
		}
		if (cal < minNum) {
			minNum = cal;
		}

		return;
	}

	vector<int> copy = op;
	if (op[0] != 0) {
		op[0]--;
		int s = cal;
		s +=  num[cnt + 1];
		dfs(cnt + 1, s, op);
		op = copy;
	}
	if (op[1] != 0) {
		op[1]--;
		int s = cal;
		s -= num[cnt + 1];
		dfs(cnt + 1, s, op);
		op = copy;
	}
	if (op[2] != 0) {
		op[2]--;
		int s = cal;
		s *= num[cnt + 1];
		dfs(cnt + 1, s, op);
		op = copy;
	}
	if (op[3] != 0) {
		op[3]--;
		int s = cal;
		s /= num[cnt + 1];
		dfs(cnt + 1, s, op);
		op = copy;
	}
}

void Solution() {
	dfs(0, num[0], oper);
	cout << maxNum << '\n' << minNum << '\n';
}

void Input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		num.push_back(tmp);
	}
	for (int i = 0; i < 4; i++) {
		int tmp;
		cin >> tmp;
		opSum += tmp;
		oper.push_back(tmp);
	}
}

int main() {
	Input();
	Solution();

	return 0;
}