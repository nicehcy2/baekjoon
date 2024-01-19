#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr1[1001], arr2[1001];

void Solution() {
    int res = 0, num = N;

    sort(arr1 + 0, arr1 + M);
    sort(arr2 + 0, arr2 + M);

    while (num > 0) {
        if (num - 6 >= 0) {
            if (arr1[0] > arr2[0] * 6) {
                res += arr2[0] * 6;
                num -= 6;
            }
            else {
                res += arr1[0];
                num -= 6;
            }
        }
        else {
            if (arr1[0] > arr2[0] * num) {
                res += arr2[0] * num;
                num = 0;
            }
            else {
                res += arr1[0];
                num -= 6;
            }
        }
    }

    cout << res << '\n';
}

void Input() {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> arr1[i] >> arr2[i];
    }
}

int main() {
    Input();
    Solution();

    return 0;
}