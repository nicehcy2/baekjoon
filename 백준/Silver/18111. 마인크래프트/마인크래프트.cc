#include <iostream>
#include <cmath>

#define INF 2100000000
using namespace std;

int N, M, B, t = 0, minTime = INF, BackB;
int arr[501][501];
int backUpArr[501][501];

void Input() {
	cin >> N >> M >> B;
	BackB = B;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			backUpArr[i][j] = arr[i][j];
		}
	}
}

void DropItem(int num) {
	B -= num;
}

void AddItem(int num) {
	B += num;
}

double checkAvgBlockHeight() {
	double sum = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			sum += arr[i][j];
		}
	}

	return sum / (N * M);
}

int checkCalcItem(int avg) {
	int ItemsNeeded = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] > avg) {
				ItemsNeeded -= (arr[i][j] - avg);
			}
			else if (arr[i][j] < avg) {
				ItemsNeeded += (avg - arr[i][j]);
			}
		}
	}

	return ItemsNeeded;
}

void deleteBlock(int i, int j, int avg) {
	int itemNum = arr[i][j] - avg;
	arr[i][j] = avg;
	DropItem(itemNum);
	t += itemNum * 2;
}

void addBlock(int i, int j, int avg) {
	int itemNum = avg - arr[i][j];
	arr[i][j] = avg;
	AddItem(itemNum);
	t += itemNum;
}

void backUp() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			arr[i][j] = backUpArr[i][j];
		}
	}
	B = BackB;
}

void Solution() {
	double avgHeight = round(checkAvgBlockHeight());
	avgHeight = 0;

	while (true) {
		int itemNeeded = checkCalcItem(avgHeight);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (avgHeight < arr[i][j]) {
					deleteBlock(i, j, avgHeight);
				}
				else if (avgHeight > arr[i][j]) {
					addBlock(i, j, avgHeight);
				}
			}
		}

		if (t <= minTime) {
			minTime = t;
		}
		else {
			avgHeight--;
			break;
		}

		avgHeight++;
		backUp();
		itemNeeded = checkCalcItem(avgHeight);
		if (B - itemNeeded < 0) {
			avgHeight--;
			break;
		}
		
		t = 0;
	}

	

	cout << minTime << " " << avgHeight << '\n';
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}