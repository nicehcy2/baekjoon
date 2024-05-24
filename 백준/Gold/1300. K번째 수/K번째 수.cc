#include <iostream>

using namespace std;

int N, K;

void Solution() {

    int start = 1, end = K, mid = 0, ans = 0;

    while (end >= start) {

        int mid = (start + end) / 2;

        int cnt = 0;
        for (int i = 1; i <= N; i++) {
            cnt += min(mid / i, N);
        }

        if (cnt < K) start = mid + 1;
        else {
            end = mid - 1;
            ans = mid;
        }
    }

    cout << ans << '\n';
}

void Input() {

    cin >> N >> K;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    Input();
    Solution();

    return 0;
}