#include <iostream>

using namespace std;

int N;
int arr[11];
int ans[11];

void Solution() {

    for (int i = 1; i <= N; i++) {

        for (int j = 0; j < N; j++) {
            if (arr[i] == 0 && ans[j] == 0) {
                ans[j] = i;
                break;
            }
            else if (ans[j] == 0) {
                arr[i]--;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';
}

void Input() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
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