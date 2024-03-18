#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, num;
vector<int> plusVec, minusVec;

void Input() {

	cin >> N;

	for (int i = 0; i < N; i++) {

		cin >> num;

		if (num > 0) plusVec.push_back(num);
		else minusVec.push_back(num);
	}
}

void Solution() {

	sort(plusVec.begin(), plusVec.end(), greater<>());
	sort(minusVec.begin(), minusVec.end());

	int ans = 0;

	if (plusVec.size() % 2 != 0) ans += plusVec[plusVec.size() - 1];
	for (int i = 0; i < (int)plusVec.size() - 1; i+=2) {
		if (plusVec[i + 1] == 1) ans += plusVec[i] + plusVec[i + 1];
		else ans += plusVec[i] * plusVec[i + 1];
	}
		
	if (minusVec.size() % 2 != 0) ans += minusVec[minusVec.size() - 1];
	for (int i = 0; i < (int)minusVec.size() - 1; i+= 2) {
		ans += minusVec[i] * minusVec[i + 1];
	}

	cout << ans << '\n';
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}