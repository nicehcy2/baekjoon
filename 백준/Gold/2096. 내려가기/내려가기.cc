#include <iostream>

using namespace std;

int N;
int minDp[3], maxDp[3], arr[3];

void Solution() {
}

void Input() {
    cin >> N;

    for (int i = 0; i < 3; i++) {
        cin >> arr[i];
    }

    maxDp[0] = arr[0], maxDp[1] = arr[1], maxDp[2] = arr[2];
    minDp[0] = arr[0], minDp[1] = arr[1], minDp[2] = arr[2];

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[j];
        }

        int max0, max1, max2, min0, min1, min2;

        max0 = max(maxDp[0], maxDp[1]) + arr[0];
        max1 = max(max(maxDp[0], maxDp[1]), maxDp[2]) + arr[1];
        max2 = max(maxDp[1], maxDp[2]) + arr[2];

        min0 = min(minDp[0], minDp[1]) + arr[0];
        min1 = min(min(minDp[0], minDp[1]), minDp[2]) + arr[1];
        min2 = min(minDp[1], minDp[2]) + arr[2];

        maxDp[0] = max0, maxDp[1] = max1, maxDp[2] = max2;
        minDp[0] = min0, minDp[1] = min1, minDp[2] = min2;
   }

    cout << max(max(maxDp[0], maxDp[1]), maxDp[2]) << " " << min(min(minDp[0], minDp[1]), minDp[2]) << '\n';
}

int main() {
    Input();
    Solution();

    return 0;
}