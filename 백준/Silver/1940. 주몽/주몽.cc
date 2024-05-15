#include <iostream>

using namespace std;

int N, M, cnt = 0;
int arr[15001];

void Solution() {

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {

            if (M == arr[i] + arr[j]) {
                cnt++;
            }
        }
    }

    cout << cnt << '\n';
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