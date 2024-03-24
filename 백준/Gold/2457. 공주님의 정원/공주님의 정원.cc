#include <iostream>
#include <algorithm>

using namespace std;

int N, startCnt = 0, arrCnt = 0;
pair<int, int> arr[100002], sArr[100002];

int dayToInt(int mm, int dd) {

	return mm * 31 + dd;
}

void Input() {
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		int sm, sd, em, ed;
		cin >> sm >> sd >> em >> ed;

		int start = dayToInt(sm, sd);
		int end = dayToInt(em, ed);

		if (start <= 94) sArr[startCnt++] = { end, start };
		else arr[arrCnt++] = { start, end };
		
	}
}

void Solution() {

	sort(sArr, sArr + startCnt, greater<>());
	sort(arr, arr + arrCnt);

	// 종료 시점으로 비교 (초기값은 1~2월에 시작한 것 중 제일 늦게 종료되는것)
	int comp = sArr[0].first, max = 0, ans = 1;

	if (comp > 371) {
		cout << ans << '\n';
		return;
	}

	for (int i = 0; i < arrCnt; i++) {
		
		if (arr[i].first <= comp) {
			
			if (max < arr[i].second) max = arr[i].second;

			if (max > 371) {
				cout << ans + 1 << '\n';
				return;
			}
		}
		else {

			comp = max;
			ans++;

			if (comp > 371) {
				cout << ans << '\n';
				return;
			}

			if (arr[i].first <= comp) {

				if (max < arr[i].second) {
					max = arr[i].second;

					if (max > 371) {
						cout << ans + 1 << '\n';
						return;
					}
				}
			}
			else {
				cout << "0\n";
				return;
			}
		}
	}

	cout << "0\n";
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}