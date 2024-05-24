#include <iostream>

using namespace std;

int N, M;
int arr[100001];

void Solution() {

    int maxVl = 0, sum = 0, start = 0, end = 0, mid = 0;

    for (int i = 0; i < N; i++) {
        maxVl = max(arr[i], maxVl);
        sum += arr[i];
    }

    start = maxVl, end = sum;

    while (end >= start) {

        mid = (start + end) / 2;

        int cnt = 1, pSum = 0;
        for (int i = 0; i < N; i++) {

            if (pSum + arr[i] > mid) {
                pSum = 0;
                cnt++;
            }
            pSum += arr[i];
        }

        if (cnt <= M) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    cout << start << '\n';
}

void Input() {

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
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