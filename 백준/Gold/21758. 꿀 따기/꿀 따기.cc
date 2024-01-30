#include <iostream>
#include <vector>

using namespace std;

int N;
long long arr[100001], sum[100001];

void Solution() {
    long long ans = 0;

    for (int i = 2; i <= N; i++) {
        ans = max(ans, sum[N] - arr[1] - arr[i] + sum[N] - sum[i]);
    }

    for (int i = N - 1; i >= 1; i--) {
        ans = max(ans, sum[N - 1] - arr[i] + sum[i - 1]);
    }


    for (int i = 2; i <= N - 1; i++) {
        ans = max(ans, sum[i] - arr[1] + sum[N - 1] - sum[i - 1]);
    }

    cout << ans << '\n';
}

void Input() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];

        sum[i] = sum[i - 1] + arr[i];
    }
}

int main() {
    Input();
    Solution();

    return 0;
}