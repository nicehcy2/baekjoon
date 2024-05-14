#include <iostream>

using namespace std;

int N, M;
int arr[1025][1025];
int prefixSum[1025][1025];

void Solution() {

    while (M--) {

        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;

        cout << prefixSum[y2][x2] - prefixSum[y2][x1 - 1] - prefixSum[y1 - 1][x2] + prefixSum[y1 - 1][x1 - 1] << '\n';
    }
}

void Input() {

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {

        for (int j = 1; j <= N; j++) {

            cin >> arr[i][j];

            prefixSum[i][j] = arr[i][j] + prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
        }
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