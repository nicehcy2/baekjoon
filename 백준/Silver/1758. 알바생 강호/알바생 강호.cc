#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[100005];

void Solution() {
    long long sum = 0;
    sort(arr + 0, arr + N, greater<>());


    for (int i = 0; i < N; i++) {
        if (arr[i] - i >= 0) {
            sum += arr[i] - i;
        }
    }

    cout << sum << '\n';
}

void Input() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

int main() {
    Input();
    Solution();

    return 0;
}