#include <iostream>

using namespace std;

int n, w, l;
int arr[2001];

void Input() {
	
	cin >> n >> w >> l;
	for (int i = w + 1; i <= w + n; i++) {
		cin >> arr[i];
	}
}

void Solution() {

	int pass = 0, time = 0;

	while (true) {
		
		int bridgeWeight = 0;

		/** 테스트
		cout << time << ": ";
		for (int i = 1; i <= w + n; i++) {
			cout << arr[i] << " ";
		} cout << '\n';
		*/

		if (pass == n) {

			cout << time << '\n';
			break;
		}

		// 다리 검사
		for (int i = 2; i <= w; i++) {
			bridgeWeight += arr[i];
		}

		// 제일 먼저 대기하고 있는 트럭을 포함한 현재 다리에 있는 트럭의 무게가 최대 하중을 초과하면? 
		if (bridgeWeight + arr[w + 1] > l) {
			// 현재 지나가고 있는 트럭을 한 칸 보냄
			if (arr[1]) {
				pass++;
			}

			for (int i = 1; i <= w; i++) {
				arr[i - 1] = arr[i];
			}
			arr[w] = 0;

		}
		// 아니면
		else {
			if (arr[1]) {
				pass++;
			}

			for (int i = 1; i <= w + n; i++) {
				arr[i - 1] = arr[i];
			}
		}

		time++;
	}
}

int main() {

	Input();
	Solution();

	return 0;
}