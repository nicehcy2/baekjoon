#include <iostream>

#define MALE 1
#define FEMALE 2

using namespace std;

int n, stuNum;
bool arr[101];

bool checkIndex(int left, int right) {
	if (left <= 0) {
		return false;
	}
	if (right > n) {
		return false;
	}
	return true;
}

bool checkSymmetry(int left, int right) {
	if (arr[left] == arr[right]) {
		return true;
	}
	else {
		return false;
	}
}

void Solution(int s, int num) {
	if (s == MALE) {
		for (int i = 1; i <= n; i++) {
			if (i % num == 0) {
				if (arr[i]) arr[i] = false;
				else arr[i] = true;
			}
		}
	}
	else if (s == FEMALE) {
		int cnt = 0;
		while (true) {
			if (!checkIndex(num - cnt - 1, num + cnt + 1)) {
				break;
			}
			if (checkSymmetry(num - cnt - 1, num + cnt + 1)) {
				cnt++;
			}
			else {
				break;
			}
		}

		if (arr[num]) arr[num] = false;
		else arr[num] = true;
		for (int i = 1; i <= cnt; i++) {
			if (arr[num - i]) arr[num - i] = false;
			else arr[num - i] = true;

			if (arr[num + i]) arr[num + i] = false;
			else arr[num + i] = true;
		}
	}
}

void Input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	cin >> stuNum;
	for (int i = 1; i <= stuNum; i++) {
		int s, num;
		cin >> s >> num;
		Solution(s, num);
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	int cnt = 0;
	for (int i = 0; i < n / 20; i++) {
		for (int j = 1; j <= 20; j++) {
			cout << arr[i * 20 + j] << " ";
		}
		cout << '\n';
		cnt++;
	}
	for (int i = 1; i <= n % 20; i++) {
		cout << arr[20 * cnt + i] << " ";
	}cout << '\n';

	return 0;
}