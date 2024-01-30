#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int arr[300001], diff[300001];

void Solution() {
    sort(arr, arr + N);

    for (int i = 0; i < N - 1; i++) {
        diff[i] = arr[i + 1] - arr[i];
    }

    sort(diff, diff + N - 1, greater<>());

    long long sum = 0;
    for (int i = K - 1; i < N; i++) {
        sum += diff[i];
    }

    cout << sum << '\n';
}

void Input() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

int main() {
    Input();
    Solution();

    return 0;
}