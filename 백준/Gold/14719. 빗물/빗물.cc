#include <iostream>

using namespace std;

int H, W;
int arr[501];

void Solution() {

    int left = 0, right = 0, ans = 0;

    for (int i = 1; i < W - 1; i++) {

        left = 0, right = 0;

        for (int j = i; j >= 0; j--) {
            if (left < arr[j]) {
                left = arr[j];
            }
        }

        for (int j = i; j < W; j++) {
            if (right < arr[j]) {
                right = arr[j];
            }
        }
        if (min(left, right) - arr[i] > 0)
            ans += min(left, right) - arr[i];
    }

    cout << ans << '\n';
}

void Input() {
    cin >> H >> W;

    for (int i = 0; i < W; i++) {
        cin >> arr[i];
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Input();
    Solution();

    return 0;
}