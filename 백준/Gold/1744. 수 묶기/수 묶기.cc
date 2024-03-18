#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, num;
vector<int> plusVec, minusVec, zeroVec;

void Input() {

	cin >> N;

	for (int i = 0; i < N; i++) {

		cin >> num;

		if (num > 0) {
			plusVec.push_back(num);
		}
		else if (num == 0) {
			zeroVec.push_back(num);
		}
		else {
			minusVec.push_back(num);
		}
	}
}

void Solution() {

	sort(plusVec.begin(), plusVec.end(), greater<>());
	sort(minusVec.begin(), minusVec.end());

	bool mulFlag = false;
	int ans = 0, plusTmp = 0;
	for (int i = 0; i < plusVec.size(); i++) {
		if (plusVec[i] == 1) {
			ans += plusVec[i];
		}
		else {
			if (mulFlag) {
				plusTmp *= plusVec[i];
				ans += plusTmp;
				mulFlag = false;
				plusTmp = 0;
			}
			else {
				plusTmp += plusVec[i];
				mulFlag = true;
			}
		}
	}
	ans += plusTmp;

	int maxMinus = 0;
	if (minusVec.size() % 2 != 0) {
		maxMinus = minusVec[minusVec.size() - 1];
		minusVec.erase(minusVec.end() - 1);
	}

	int minusTmp = 0;
	mulFlag = false;
	for (int i = 0; i < minusVec.size(); i++) {
		if (mulFlag) {
			minusTmp *= minusVec[i];
			ans += minusTmp;
			mulFlag = false;
			minusTmp = 0;
		}
		else {
			minusTmp += minusVec[i];
			mulFlag = true;
		}
	}

	if (maxMinus != 0) {
		if (zeroVec.empty()) {
			ans += maxMinus;
		}
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