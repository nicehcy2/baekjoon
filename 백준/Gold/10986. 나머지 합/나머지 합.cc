#include <iostream>

using namespace std;

int N, M;
long long A[1000001], S[1000001];
long long h[10001];

void Solution() {

	long long ans = 0;

	// 구간 합을 M으로 나눈다 -> 나눠서 0이 되면 만족하기 때문.
	for (int i = 0; i < N; i++) {
		S[i] %= M;

		// 나눠서 0이 되는 배열 찾기
		if (!S[i]) ans++;

		// 같은 수의 개수 찾기 -> 같은 수 두개를 빼면 조건에 만족하는 구간합임.
		h[S[i]]++;
	}

	// 개수 구하기 (nC2)
	for (int i = 0; i < M; i++) {
		ans += (h[i] * (h[i] - 1) / 2);
	}

	cout << ans << '\n';
}

void Input() {

	cin >> N >> M;

	cin >> A[0];
	S[0] = A[0];
	for (int i = 1; i < N; i++) {
		cin >> A[i];

		S[i] = S[i - 1] + A[i];
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	Solution();

	return 0;
}