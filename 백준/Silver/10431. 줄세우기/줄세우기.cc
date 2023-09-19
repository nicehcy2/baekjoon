#include <iostream>
#include <cstring>

using namespace std;

int p;
int arr[21];

void init() {
	cin >> p;
}

void Solution() {
	while (p--) {
		int num;
		cin >> num;
		for (int i = 0; i < 20; i++) {
			cin >> arr[i];
		}

		int count = 0;
		for (int i = 1; i < 20; i++) {
			for (int j = i - 1; j >= 0; j--) {
				int flag = false;
				if (arr[j] > arr[i]) {
					count++;
					flag = true;
					if (j == 0) {
						int temp = arr[i];
						for (int k = i - 1; k >= j; k--) {
							arr[k + 1] = arr[k];
						}
						arr[j] = temp;
					}
				}
				else {
					if (flag) {
						int temp = arr[i];
						for (int k = i - 1; k >= j + 1; k--) {
							arr[k + 1] = arr[k];
						}arr[j] = temp;
					}
					
				}
			}
		}

		cout << num << " " << count << '\n';
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