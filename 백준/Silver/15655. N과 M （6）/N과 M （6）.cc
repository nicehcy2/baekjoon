#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[9];

int res[9];

void Recursion(int cnt, int start) {
    if (cnt == M) {
        for (int i = 0; i < M; i++) {
            cout << res[i] << " ";
        } cout << '\n';

        return;
    }

    for (int i = start; i < N; i++) {
        res[cnt] = arr[i];
        Recursion(cnt + 1, i + 1);
    }
}

void Solution() {
    sort(arr, arr + N);
    Recursion(0, 0);
}

void Input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

int main() {
    Input();
    Solution();

    return 0;
}